Need:
- CUDA Version 9.2+
- NVIDIA Driver Version: 396.37+
- Recommend: 1080ti, 2080ti, titan V, titan RTX

Step:
1. tar -zxvf cortex_miner.tar.gz
2. cd cortex_miner
3. config start.sh
```
worker='your worker name'
pool_uri='the remote pool uri, example: xxxx@xxx.com:port'
pool_uri_1='the first candidate pool uri'
pool_uri_2='the second candidate pool uri'
device=the devices used mining, example:0,1,2,3,4,5,6,7,8
account='you wallet address, example:0x0000000000000000000000000'
```
example:
```
worker='miner1'
pool_uri='xxxx@xxx.com:port'
pool_uri_1='yyy@yy.com:port'
pool_uri_2='127.0.0.1:port'
device=0,1,2,3
account='0x0000000000000000000000000'
```
4. chmod +x start.sh
5. ./start.sh

### pool address
Recommend : cuckoo.cortexmint.com:8008
