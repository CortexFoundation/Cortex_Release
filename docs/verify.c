#define EDGEBITS 30
#define PROOFSIZE 42
#define EDGE_BLOCK_BITS 6
#define EDGE_BLOCK_SIZE (1 << EDGE_BLOCK_BITS)
#define EDGE_BLOCK_MASK (EDGE_BLOCK_SIZE - 1)

typedef struct {
    u64 k0;
    u64 k1;
    u64 k2;
    u64 k3;
  } siphash_keys;

#define ROTL(x,b) (u64)( ((x) << (b)) | ( (x) >> (64 - (b))) )
  #define SIPROUND \
    do { \
      v0 += v1; v2 += v3; v1 = ROTL(v1,13); \
      v3 = ROTL(v3,16); v1 ^= v0; v3 ^= v2; \
      v0 = ROTL(v0,32); v2 += v1; v0 += v3; \
      v1 = ROTL(v1,17);   v3 = ROTL(v3,21); \
      v1 ^= v2; v3 ^= v0; v2 = ROTL(v2,32); \
    } while(0)

u64 sipblock(siphash_keys *key,  node_t edge, u64 *buf) {
	siphash_keys keys = *key;
	u64 v0 = keys.k0, v1 = keys.k1, v2 = keys.k2, v3 = keys.k3;

	edge_t edge0 = edge & ~EDGE_BLOCK_MASK;
	u32 i;
	for (i=0; i < EDGE_BLOCK_SIZE; i++) {
		//shs.hash24(edge0 + i);
		edge_t nonce = edge0 + i;
		v3^=nonce;
		SIPROUND; SIPROUND;
		SIPROUND; SIPROUND;
		v0 ^= nonce;
		v2 ^= 0xff;
		SIPROUND; SIPROUND; SIPROUND; SIPROUND;
		SIPROUND; SIPROUND; SIPROUND; SIPROUND;

		//    buf[i] = shs.xor_lanes();
		buf[i] = (v0 ^ v1) ^ (v2  ^ v3);
	}
	const u64 last = buf[EDGE_BLOCK_MASK];
	for (u32 i=0; i < EDGE_BLOCK_MASK; i++)
		buf[i] ^= last;
	return buf[edge & EDGE_BLOCK_MASK];
}

int verify_proof_cuckaroo(edge_t* edges, siphash_keys *keys) {
  const uint32_t edgemask = ((edge_t)((node_t)1 << EDGEBITS) - 1);
  u64 sips[EDGE_BLOCK_SIZE];
  node_t uvs[2*PROOFSIZE];
  node_t xor0 = 0, xor1  =0;
  for (u32 n = 0; n < PROOFSIZE; n++) {
    if (edges[n] > edgemask)
      return POW_TOO_BIG;
    if (n && edges[n] <= edges[n-1])
      return POW_TOO_SMALL;
    u64 edge = sipblock(keys, edges[n], sips);
    xor0 ^= uvs[2*n  ] = edge & EDGEMASK;
    xor1 ^= uvs[2*n+1] = (edge >> 32) & EDGEMASK;
  }
  if (xor0|xor1)              // optional check for obviously bad proofs
    return POW_NON_MATCHING;
  u32 n = 0, i = 0, j;
  do {                        // follow cycle
    for (u32 k = j = i; (k = (k+2) % (2*PROOFSIZE)) != i; ) {
      if (uvs[k] == uvs[i]) { // find other edge endpoint identical to one at i
        if (j != i)           // already found one before
          return POW_BRANCH;
        j = k;
      }
    }
    if (j == i) return POW_DEAD_END;  // no matching endpoint
    i = j^1;
    n++;
  } while (i != 0);           // must cycle back to start or we would have found branch
  return n == PROOFSIZE ? POW_OK : POW_SHORT_CYCLE;
}
