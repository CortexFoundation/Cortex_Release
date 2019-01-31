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

----------

### Install CUDA 9.2 (Without NVIDIA Driver)

    wget https://developer.nvidia.com/compute/cuda/9.2/Prod2/local_installers/cuda_9.2.148_396.37_linux
    mv cuda_9.2.148_396.37_linux cuda_9.2.148_396.37_linux.run
    sudo sh cuda_9.2.148_396.37_linux.run
    (IMPORTANT: don't install driver here!!!)

----

## Install Go 1.10 or 1.11

You can install go-1.11 directly,

    wget -q https://dl.google.com/go/go1.11.5.linux-amd64.tar.gz
    sudo tar -C /usr/local -xzf go1.11.5.linux-amd64.tar.gz
    export PATH=$PATH:/usr/local/go/bin

or use a package manager you prefer. eg,

    sudo apt install golang-1.10

-----

### Building the source

Once the dependencies are installed, run

    make -j cortex
    
The compiled binary files are located in the ./build/bin,
    
    ./build/bin/cortex
    
----

## 2. Run the fullnode

### Fullnode Executables

    ./cortex --port 37566 --rpc --rpccorsdomain '*' --rpcport 30089 --rpcaddr 127.0.0.1 --rpcapi web3,eth,ctx,miner,net,txpool --verbosity 4 --storage --cerebro --gcmode archive --rpcaddr 127.0.0.1
