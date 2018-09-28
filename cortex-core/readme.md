# Cortex Readme

## System Requirements

Cortex testnet node is only tested in Ubuntu 16.04 x64 + CUDA 9.0 environment, with a CUDA platform whose compute capability >= 6.0

## Cortex Full Node

### Command

#### help

Print cortex binary help statement.

#### init

Init cortex node from configuration

### Options

#### --storage [Necessary]

This flag is used for enable P2P storage, a normal node with local infer must set this.

**--storage.dir**

Set the P2P network data storage directory.

**--storage.tracker**

To avoid long delay in P2P network for data, you can set tracker manually.

By default, a pre-defined tracker is available.

#### --datadir

Set cortex binary data directory.

#### --networkid

Set Cerebro test network id, by default 42.

#### --port

Set cortex binary listening port.

#### --bootnodes [Necessary]

Set which node cortex binary to connect, more details is as below.

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

And then, run commands to start full node `cortex`:

```Bash
./bin/cortex init bin/genesis.json

./bin/cortex --port 37565 --storage --networkid 42 --bootnodes "enode://d73a0e572ae4a710a228ca39f5cdd83c366fee7cbee25249eb354463cbfb3b07f85d1b5382bdbde5d26dc8c11c6240cc4f80c5c57e71b760c39797185da0f123@47.74.15.143:37566,enode://0d6eedee4ed1c4a1b9f273de9ed28fb30581b3bad6b733609870b39ed5a716cc59c5067deb1a43570b15f5965ab22ac04c7067a79aef1e240667d78e8ffdf81d@47.254.135.53:37566,enode://c8119e731b29bed3222ee5e63ec514926fa683f0bc999c73ff171d54a3100aea4211d70640bf937d1d61d39fdf313470b131213ae11ddfea5ccb96669f603749@47.88.174.57:37566,enode://a4d20d02a05c3674791f1a0cf9900f0db50485037f96c99395287e931a6845f624e16adbce9e84e7106f803278360979e6a6999b7ca8c25cf64b4445a6de75e6@47.52.39.170:37566"
```

Wait a few seconds, and enjoy yourself.


## Miner

MinerPool Website ：https://pool.cortexlabs.ai/

MinerPool Uri：miner-cn.cortexlabs.ai:8009  or   miner.cortexlabs.ai:8009

### Options

#### --pool_uri [Necessary]

Set the miner pool uri for work submitting.

**--devicetype**

Set the mining devices, value should be "gpu" or "cpu".

**--deviceid**

Set the number of mining devices.

**--verbosity**

Set the verbosity of log printing.

```Bash
./bin/miner -pool_uri miner-cn.cortexlabs.ai:8009 -devicetype gpu -verbosity 5 -deviceid 0
```
