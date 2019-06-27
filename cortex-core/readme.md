# Cortex Readme

## System Requirements

Cortex node is developed in Ubuntu 16.04 x64 + CUDA 9.2 + NVIDIA Driver 396.37 environment, with CUDA Compute capability >= 6.1. Latest Ubuntu distributions are also compatible, but not fully tested.

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

### Running Bash

And then, run any command to start full node `cortex`:

```Bash
1. cd cortex
2. export LD_LIBRARY_PATH=./:$LD_LIBRARY_PATH
3. ./cortex 
4. ./cortex --storage.dir ~/data/ctxc --verbosity 4
5. ./cortex --datadir ~/.cortex --storage.dir ~/.cortex/storage --verbosity 4
```
