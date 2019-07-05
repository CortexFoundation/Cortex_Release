# Cortex Readme

## System Requirements
### ubuntu
Cortex node is developed in Ubuntu 16.04 x64 + CUDA 9.2 + NVIDIA Driver 396.37 environment, with CUDA Compute capability >= 6.1. Latest Ubuntu distributions are also compatible, but not fully tested.
Recommend:
- cmake 1.10.0+
- go 1.10.0+
- gcc/g++ 5.4+
- cuda 9.2+ (if u have gpu)
```
export LD_LIBRARY_PATH=/usr/local/cuda/lib64/:/usr/local/cuda/lib64/stubs:$LD_LIBRARY_PATH
export LIBRARY_PATH=/usr/local/cuda/lib64/:/usr/local/cuda/lib64/stubs:$LIBRARY_PATH
```
- nvidia driver 396.37+
- ubuntu 16.04+
### centos
Recommend:
- cmake 1.10.0+
- go 1.10.0+
- gcc/g++ 5.4+
- cuda 10.1+ (if u have gpu)
```
export LD_LIBRARY_PATH=/usr/local/cuda/lib64/:/usr/local/cuda/lib64/stubs:$LD_LIBRARY_PATH
export LIBRARY_PATH=/usr/local/cuda/lib64/:/usr/local/cuda/lib64/stubs:$LIBRARY_PATH
```
- nvidia driver 418.67+
- centos 7.6

## Cortex Full Node

### Command

#### help

Print Cortex binary help statements.

### Options

#### --storage [Optional]

Setting this flag enables synchronization of Cortex storage layer, a standard fullnode with inference engine must set this.

**--storage.dir**

Set the directory of Cortex storage layer. By default, `$HOME/.cortex/storage` the directory is the storage dir.

#### --datadir

Set Cortex binary data directory. By default, `$HOME/.cortex/` is data directory.

#### --networkid

Set Cortex blockchain network id, Cortex Mainnet Arnold use 21 by default.

#### --port

Set Cortex binary listening port.

#### --verbosity

Set logging level to print, by default is 3, range in [1, 5], which represent Error, Warn, Info, Debug, Trace.
### Compile Source Code
1. git clone https://github.com/CortexFoundation/CortexTheseus.git
2. cd CortexTheseus
3. make cortex_cpu or make cortex (cpu and gpu)

### Running Bash

And then, run any command to start full node `cortex`:

```Bash
1. cd cortex
2. export LD_LIBRARY_PATH=./:$LD_LIBRARY_PATH
3. ./cortex —syncmode fast
```


