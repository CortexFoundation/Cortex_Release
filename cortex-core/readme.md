# Cortex Readme

## System Requirements

Cortex testnet node is developed in Ubuntu 16.04 x64 + CUDA 9.0 environment, with CUDA Compute capability >= 6.0. Latest Ubuntu distributions are also compatible, but not fully tested.

## Cortex Full Node

### Command

#### help

Print Cortex binary help statements.

#### init

Init Cortex node from a genesis configuration file

### Options

#### IMPORTANT! --cerebro

Setting `--cerebro` flag to enable connection to Cerebro testnet.

Notice: When this flag is enabled, datadir will be located at `$HOME/.cortex/cerebro/` by default, which different from `$HOME/.cortex/` in the previous version, be noticed to set datadir if restart from the previous version with default directory.  

#### --storage [Necessary]

Setting this flag enables synchronization of Cortex storage layer, a standard fullnode with inference engine must set this.

**--storage.dir**

Set the directory of Cortex storage layer. By default, `$HOME/.cortex/storage` the directory is the storage dir.

**--storage.tracker**

To alleviate the latency of finding the torrent file in P2P network, you can set torrent tracker manually.

By default, a pre-defined tracker is available.

#### --datadir

Set Cortex binary data directory. By default, `$HOME/.cortex/` is data directory.

#### --networkid

Set Cortex blockchain network id, Cerebro testnet is 42 by default.

#### --port

Set Cortex binary listening port.

#### --bootnodes [Options]

Set bootnodes of Cortex blockchain.

#### --verbosity

Set logging level to print, by default is 3, range in [1, 5], which represent Error, Warn, Info, Debug, Trace.

### Running Bash

This is a genesis config json file, please copy and paste it into a file such as `genesis.json`:

```json
{
    "config": {
        "chainId": 42,
        "homesteadBlock": 0,
        "eip155Block": 0,
        "eip158Block": 0,
        "byzantiumBlock": 0
    },
    "alloc"      : {},
    "coinbase"   : "0x0000000000000000000000000000000000000000",
    "difficulty" : "0x1",
    "extraData"  : "",
    "gasLimit"   : "0x2fefd8",
    "nonce"      : "0x0000000000000042",
    "mixhash"    : "0x0000000000000000000000000000000000000000000000000000000000000000",
    "parentHash" : "0x0000000000000000000000000000000000000000000000000000000000000000",
    "timestamp"  : "0x00"
}
```

And then, run any command to start full node `cortex`:

```Bash
Using --cerebro flag:
1. ./bin/cortex --cerebro --storage
2. ./bin/cortex --cerebro --storage --storage.dir ~/data/ctxc --verbosity 4
3. ./bin/cortex --cerebro --datadir ~/.cortex/cerebro --storage --storage.dir ~/.cortex/cerebro/storage --verbosity 4

Set cortex-core binary manually:
./bin/cortex init bin/genesis.json
./bin/cortex --port 37565 --storage --networkid 42 --bootnodes "enode://5091a81e18f722e6aa8fa7fd887836a4e030b6117ec0d11a7024871a4b9c5bfde35ee60063145f0b3bb2ec5def3fae941423fa7dc6d57f3fe23920242ea8d184@47.74.15.143:37566,enode://0778ac6fe1a572a2f5834452c1d4b6f77b57a2a4baa72e0e2582ad0dbfe88f41e4e66aa020a451a32936a86c29788d257ccaa19f58e5676943595b945e615b9e@139.224.132.6:37566,enode://0d6eedee4ed1c4a1b9f273de9ed28fb30581b3bad6b733609870b39ed5a716cc59c5067deb1a43570b15f5965ab22ac04c7067a79aef1e240667d78e8ffdf81d@47.254.135.53:37566,enode://c8119e731b29bed3222ee5e63ec514926fa683f0bc999c73ff171d54a3100aea4211d70640bf937d1d61d39fdf313470b131213ae11ddfea5ccb96669f603749@47.88.174.57:37566"
```

Wait a few seconds, and enjoy yourself.


## Miner

MinerPool Website ：https://pool.cortexlabs.ai/

MinerPool Uri：miner-cn.cortexlabs.ai:8009  or   miner.cortexlabs.ai:8009

We provide two miners for Cuda and OpenCL, which have been tested in many environments such as AMD vega64, NVIDIA 2080Ti, 1080Ti, 1080.

### Options

#### --account

Set miner account

#### --pool_uri [Necessary]

Set the miner pool URI for submitting solutions.

#### --deviceids [id1,id2,id3]

Set which GPU device use for mining, param is device ids concatenated by commas.

#### --verbosity

Set the verbosity of log printing.

### Running Bash

```Bash
./bin/miner --pool_uri miner-cn.cortexlabs.ai:8009 --verbosity 5 --deviceids 0
./bin/miner --account "0xe291d43ad2eb6ea04e9f5e1a0c67f970702f8bd6" --pool_uri miner-cn.cortexlabs.ai:8009 --verbosity 5 --deviceids 0,1,2,3
```
