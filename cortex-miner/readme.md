### Need:
- CUDA Version 9.2+
- NVIDIA Driver Version: 396.37+
- GPU Memory > 10.7G
  1. Below is the recommended minimum requirements for the official miner. Third party miners may be available after the Mainnet release which might be optimized to use less memory.
  2. Recommend: 1080ti, 2080ti, titan V, titan RTX

### Step:
1. download [cortex_miner.tar.gz](https://github.com/CortexFoundation/Cortex_Release/raw/master/cortex-miner/cortex_miner.tar.gz)
2. tar -zxvf cortex_miner.tar.gz
3. cd cortex_miner
4. start by shell:
- vim start.sh and update the parameters, example:
```
worker='miner1'
pool_uri='xxxx@xxx.com:port'
pool_uri_1='yyy@yy.com:port'
pool_uri_2='127.0.0.1:port'
device=0,1,2,3
account='0x0000000000000000000000000'
```
- chmod +x start.sh
- ./start.sh
5. start by command:
- ./cortex_miner -pool_uri=Pool_IP:Port -worker=Your_Worker_name -devices=Your_GPU_Ids -account=Your_Wallet_Address

### pool address
- Recommend : cuckoo.cortexmint.com:8008
- The Pool Link : www.cortexmint.com/
