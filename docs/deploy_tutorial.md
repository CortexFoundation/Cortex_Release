# Cortex Fullnode

Official golang implementation of the Cortex fullnode.

## 1. Requirements

### 
Building cortex requires a Go (version 1.7 or later), a C compiler, and a CUDA (version 9.2 or later).

-----------

### Install NVIDIA Driver

Download the driver first,

    wget http://us.download.nvidia.com/XFree86/Linux-x86_64/410.93/NVIDIA-Linux-x86_64-410.93.run
    chmod +x NVIDIA-Linux-x86_64-410.93.run

Remove old driver,

    sudo apt-get remove --purge nvidia*
    sudo apt-get install build-essential freeglut3-dev libx11-dev libxmu-dev libxi-dev libgl1-mesa-glx libglu1-mesa libglu1-mesa-dev
    sudo nano /etc/modprobe.d/blacklist-nouveau.conf

Paste the following content into the text editor and save it,

    blacklist nouveau
    options nouveau modeset=0

Press Ctrl + Alt + F1 to enter tty1 console,
 
    sudo update-initramfs -u
    sudo service lightdm stop
    sudo ./NVIDIA-Linux-x86_64-410.93.run –no-opengl-files
    (do not apply xorg config here!!!!)

Then,

    sudo service lightdm start

Press Ctrl + Alt + F7 to go back tty7 interface.

----------


### Install NVIDIA Driver via PPA repository

    sudo apt-get remove --purge nvidia*
    sudo apt-get install build-essential freeglut3-dev libx11-dev libxmu-dev libxi-dev libgl1-mesa-glx libglu1-mesa libglu1-mesa-dev
    sudo nano /etc/modprobe.d/blacklist-nouveau.conf
    

Paste the following content into the text editor and save it,

    blacklist nouveau
    options nouveau modeset=0

Install NVIDIA Driver via PPA repository,

    sudo add-apt-repository ppa:graphics-drivers/ppa
    sudo apt-get update

Press Ctrl + Alt + F1 to enter tty1 console,
 
    sudo update-initramfs -u
    sudo service lightdm stop

    sudo apt-get install nvidia-410
    sudo apt-get install mesa-common-dev
    sudo apt-get install freeglut3-dev

Then,

    sudo service lightdm start

Press Ctrl + Alt + F7 to go back tty7 interface.

### How to Install Latest Nvidia Drivers on Ubuntu 16.04

[Click Here](https://rajat-osgyan.blogspot.com/2016/04/how-to-install-latest-nvidia-drivers-on.html)

### How to solve the login loop problem

[csdn answer 1](https://blog.csdn.net/zhwisdom0427/article/details/73662433)

[csdn answer 2](https://blog.csdn.net/gaowu959/article/details/79596724)

[csdn answer 3](https://blog.csdn.net/QLULIBIN/article/details/79568916)

[Login loop after upgrade to 16.04](https://askubuntu.com/questions/760492/login-loop-after-upgrade-to-16-04)

### Make sure you have installed NVIDIA driver successfully

Run

    nvidia-smi

and check the driver status.

----

### Install CUDA 10.0 (Without NVIDIA Driver)

    wget https://developer.nvidia.com/compute/cuda/10.0/Prod/ local_installers/cuda_10.0.130_410.48_linux
    mv cuda_10.0.130_410.48_linux cuda_10.0.130_410.48_linux.run
    sudo sh cuda_10.0.130_410.48_linux.run
    sudo ldconfig /usr/local/cuda/lib64
    (IMPORTANT: don't install driver here!!!)

### OR Install CUDA 9.2 (Without NVIDIA Driver)

    wget https://developer.nvidia.com/compute/cuda/9.2/Prod2/local_installers/cuda_9.2.148_396.37_linux
    mv cuda_9.2.148_396.37_linux cuda_9.2.148_396.37_linux.run
    sudo sh cuda_9.2.148_396.37_linux.run
    sudo ldconfig /usr/local/cuda/lib64
    (IMPORTANT: don't install driver here!!!)

----

## Install Go 1.10 or 1.11

You can install go-1.11 directly,

    wget https://dl.google.com/go/go1.11.5.linux-amd64.tar.gz
    sudo tar -C /usr/local -xzf go1.11.5.linux-amd64.tar.gz
    echo 'export PATH="$PATH:/usr/local/go/bin"' >> ~/.bashrc
    source ~/.bashrc

or use a package manager you prefer. eg,

    sudo apt install golang-1.10

Check your go version here,

    go version


-----

### Building the source

Clone the source (Need permission)

    git clone git@github.com:CortexFoundation/CortexTheseus.git --branch dev-cerebro
    (with git accessable key)
    git clone http://github.com/CortexFoundation/CortexTheseus --branch dev-cerebro
    (with git accessable account)

    cd CortexTheseus

Once the dependencies are installed, run

    cd infernet && make clean
    cd .. && make clean
    make -j cortex

Save the executable file,

    sudo mkdir -p /serving/cortex-core/bin
    sudo chmod 777 /serving/cortex-core/bin
    cp build/bin/cortex /serving/cortex-core/bin/cortex
    
The compiled binary files are located in the ./build/bin,
    
    ./build/bin/cortex
    
----

## 2. Run the fullnode

### Download the executable file directly

    sudo mkdir -p /serving/cortex-core/bin
    cd /serving/cortex-core/bin
    sudo chmod 777 .

Ubuntu 16.04, CUDA 9.0

    wget https://raw.githubusercontent.com/CortexFoundation/Cortex_Release/master/cortex-core/bin/cortex-Ubuntu-16.04-cuda-9.0
    mv cortex-Ubuntu-16.04-cuda-9.0 cortex

Ubuntu 16.04, CUDA 9.2

    wget https://raw.githubusercontent.com/CortexFoundation/Cortex_Release/master/cortex-core/bin/cortex-Ubuntu-16.04-cuda-9.2
    mv cortex-Ubuntu-16.04-cuda-9.2 cortex

Ubuntu 16.04, CUDA 10.0

    wget https://raw.githubusercontent.com/CortexFoundation/Cortex_Release/master/cortex-core/bin/cortex-Ubuntu-16.04-cuda-10.0
    mv cortex-Ubuntu-16.04-cuda-10.0 cortex

Ubuntu 18.04, CUDA 9.2

    wget https://raw.githubusercontent.com/CortexFoundation/Cortex_Release/master/cortex-core/bin/cortex-Ubuntu-18.04-cuda-9.2
    mv cortex-Ubuntu-18.04-cuda-9.2 cortex

Ubuntu 18.04, CUDA 10.0

    wget https://raw.githubusercontent.com/CortexFoundation/Cortex_Release/master/cortex-core/bin/cortex-Ubuntu-18.04-cuda-10.0
    mv cortex-Ubuntu-18.04-cuda-10.0 cortex

----


### Fullnode executables directly

    ./cortex --port 37566 --rpc --rpccorsdomain '*' --rpcport 30089 --rpcaddr 127.0.0.1 --rpcapi web3,eth,ctx,miner,net,txpool --verbosity 4 --storage --cerebro --gcmode archive --rpcaddr 127.0.0.1

### Fullnode executables via supervisor

#### Create bash script

    rm /serving/cortex-core/bin/cortex.sh
    sudo nano /serving/cortex-core/bin/cortex.sh

Create /serving/cortex-core/bin/cortex.sh

    #!/bin/bash
    export LD_LIBRARY_PATH=/usr/local/cuda/lib64${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}
    /serving/cortex-core/bin/cortex --port 37566 --rpc --rpccorsdomain '*' --rpcport 30089 --rpcaddr 127.0.0.1 --rpcapi web3,eth,ctx,miner,net,txpool --verbosity 4 --storage --cerebro --gcmode archive --rpcaddr 127.0.0.1

Make the script executable,

    chmod +x /serving/cortex-core/bin/cortex.sh

#### config

    [program:cortexnode]
    directory=/serving/cortex-core/bin/
    command=bash /serving/cortex-core/bin/cortex.sh
    autostart=true
    autorestart=true
    startsecs=5
    stderr_logfile=/tmp/cortex_fullnode_stderr.log
    stdout_logfile=/tmp/cortex_fullnode_stdout.log

#### check running status

    sudo supervisorctl tail cortexnode stdout

----
### Fullnode parameters

#### Command

use the parameter directly.

|parameter| description |
----|----
|help|Print Cortex binary help statements.|
|init|Init Cortex node from a genesis configuration file|

#### Options

use "--" prefix with the parameter.

|       parameter     | description | 
--------------------- | -------------
| cerebro | Setting --cerebro flag to enable connection to Cerebro testnet.
| | Notice: When this flag is enabled, datadir will be located at $HOME/.cortex/cerebro/ by default, which different from $HOME/.cortex/ in the previous version, be noticed to set datadir if restart from the previous version with default directory.|
| storage | [Necessary] |
| |Setting this flag enables synchronization of Cortex storage layer, a standard fullnode with inference engine must set this.|
| storage.dir|Set the directory of Cortex storage layer. By default, $HOME/.cortex/storage the directory is the storage dir.|
|storage.tracker|To alleviate the latency of finding the torrent file in P2P network, you can set torrent tracker manually. By default, a pre-defined tracker is available.|
|datadir|Set Cortex binary data directory. By default, $HOME/.cortex/ is data directory.|
|networkid|Set Cortex blockchain network id, Cerebro testnet is 42 by default.|
|port|Set Cortex binary listening port.|
|bootnodes| [Options]|
||Set bootnodes of Cortex blockchain.|
|verbosity|Set logging level to print, by default is 3, range in [1, 5], which represent Error, Warn, Info, Debug, Trace.|

