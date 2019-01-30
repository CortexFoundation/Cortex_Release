# Cortex Fullnode

Official golang implementation of the Cortex fullnode.

## 1. Run cortex fullnode from source code.

### Clone the source (Need permission)

    git clone git@github.com:CortexFoundation/CortexTheseus.git --branch wlt-cerebro
    cd CortexTheseus

### Install Golang 1.11

    wget -q https://dl.google.com/go/go1.11.5.linux-amd64.tar.gz
    sudo tar -C /usr/local -xzf go1.11.5.linux-amd64.tar.gz
    export PATH=$PATH:/usr/local/go/bin

### Install CUDA 9.2 (With Nvidia Driver)

    wget https://developer.nvidia.com/compute/cuda/9.2/Prod2/local_installers/cuda_9.2.148_396.37_linux
    sudo sh cuda_9.2.148_396.37_linux.run

### Install Nvidia Driver 
    If your CUDA Driver version is not 396.26 or later
    see appendix.

### Building the source

Building geth requires both a Go (version 1.7 or later), a C compiler, and CUDA 9.2 (CUDA Driver version 396.26 or later).
You can install them using your favourite package manager.
Once the dependencies are installed, run

    make all

### Fullnode Executables

    ./build/bin/cortex --port 37566 --rpc --rpccorsdomain '*' --rpcport 30089 --rpcaddr 127.0.0.1 --rpcapi web3,eth,ctx,miner,net,txpool --verbosity 4 --storage --cerebro --gcmode archive --rpcaddr 127.0.0.1

## 2. Run cortex fullnode from binary.

### Get the binary file "/build/bin/cortex".

### Install CUDA 9.2 (With Nvidia Driver)

    wget https://developer.nvidia.com/compute/cuda/9.2/Prod2/local_installers/cuda_9.2.148_396.37_linux
    sudo sh cuda_9.2.148_396.37_linux.run

### Install Nvidia Driver 
    If your CUDA Driver version is not 396.26 or later
    see appendix.
    
### Fullnode Executables

    ./cortex --port 37566 --rpc --rpccorsdomain '*' --rpcport 30089 --rpcaddr 127.0.0.1 --rpcapi web3,eth,ctx,miner,net,txpool --verbosity 4 --storage --cerebro --gcmode archive --rpcaddr 127.0.0.1

# Appendix


## Install Go 1.10 or 1.11

You can install go-1.11 directly,

    wget -q https://dl.google.com/go/go1.11.5.linux-amd64.tar.gz
    sudo tar -C /usr/local -xzf go1.11.5.linux-amd64.tar.gz
    export PATH=$PATH:/usr/local/go/bin

or use a package manager you prefer. eg,

    sudo apt install golang-1.10




## Install Nvidia Driver on Ubuntu 16.04

    sudo apt-get remove --purge nvidia*
    sudo apt-get install build-essential pkg-config xserver-xorg-dev 
    sudo vim /etc/modprobe.d/blacklist-nouveau.conf

blacklist-nouveau.conf:

    blacklist nouveau
    options nouveau modeset=0

Press Ctrl + Alt + F1 to enter tty1 console,
 
    sudo update-initramfs -u
    sudo service lightdm stop
    sudo sh ./NVIDIA*.run

You can also install NVIDIA Driver via PPA repository,

    sudo add-apt-repository ppa:graphics-drivers/ppa
    sudo apt-get update
    sudo apt-get install nvidia-396
    sudo apt-get install mesa-common-dev
    sudo apt-get install freeglut3-dev

Then,

    sudo service lightdm start

Press Ctrl + Alt + F7 to go back tty7 interface.
