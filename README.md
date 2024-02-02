## About
Code for IEEE S&P 2023 - DEVFUZZ: Automatic Device Model-Guided Device Driver Fuzzing

## Dependency
### LLVM-13
install LLVM-13:   
```
sudo ./llvm.sh 13 all
```

### WLLVM
WLLVM is used for performing static analysis on Linux

Install with pip:
```
pip install wllvm
```

## Build  DevFuzz
First, We need to build QEMU, AFL, AFL-Proxy and S2E

Under the project directory, Run:
```
make
```

Second, We need to build a image for fuzzing:
```
cd images
./build-image.sh
```
This will produce a debian image called stretch.img

At last, We need a image for S2E:
### Build From Scratch
TODO

### Use Pre-built Image
You can download a image from our google drive and extract it to **s2e/images/**
Download link  can be found inside s2e-image-link.txt

## Build Linux Kernel for Fuzzing
Clone a verison  of Linux Kernel (e.g. v5.15)
```
git clone --depth 1 --branch v5.15 https://github.com/torvalds/linux.git
```
Config the Kernel, include all the drivers you want to test as kernel modules  
Examples:
```
cd linux
make defconfig / allmodconfig / menuconfig
```
Or use an existing config
```
mv ../config-linux-5.15 .config
``` 
Apply the patch
```
git apply ../afl-proxy/stage2-guest-kernel-patch/<Patch Name>
```

Compile the kernel
```
./tools/shell_scripts/compile_and_deploy.sh
```


## Build Linux Kernel for Static Analysis
In the project directory:
```
mkdir analysis && cd analysis
git clone --depth 1 --branch v5.15 https://github.com/torvalds/linux.git
```
Config the kernel, include all the drivers you want to analyze as kernel modules
Examples:
```
cd linux
make allmodconfig
``` 

Compile the kernel with WLLVM
```
# in the root of project directory
./wllvm-compile-linux.sh
``` 

Extract Bitcode from a kernel module

Example:
```
extract-bc analysis/linux/drivers/net/ethernet/intel/e1000/e1000_main.o -l /usr/bin/llvm-link-13
``` 

## Fuzzing with Device Models
This projects ships with over 100 pre-built device models that you can perform fuzzing with. You can also build device models by yourself, which is covered in the next section. All the PCI devices are listed in **afl-proxy/aplib/pci**

### Probing Phase Fuzzing
#### Prepare Test Script
```
echo "./probe.sh" > .bashrc
./tools/shell_scripts/transfer-to-img.sh .bashrc
```

In one terminal:
```
sudo python3 ./tools/launch-afl.py -s <SHMID> -c <CORE>
```
In other terminal:
```
sudo python3 ./tools/fuzz_probe.py -c <CORE> -s <SHMID> -d <DEVICE> -p <PROB> -m <MODE>
```
They must use the same CORE (cpu id) and SHMID (shared memory id).

Example:
```
sudo python3 ./tools/launch-afl.py -s 0 -c 0
sudo python3 ./tools/fuzz_probe.py -c 0 -s 0 -d e1000 -p 50 -m fuzz
```

### Post-Probing Phase Fuzzing
#### Prepare a test script
You can have a custom test scripts to drive the device, some examples can be found in tools/test test_scripts. You can use **tools/shell_scripts/transfer-to-img.sh** to transfer a you custom scripts into the image. For example, to have a script running automatically on boot to test the Ethernet NICs, you need to insert "./test-nic.sh" into .bashrc and put it inside the image.

Fuzzing is similar to Probing Phase Fuzzing.
Example:
```
# In two seperate terminals
sudo python3 ./tools/launch-afl.py -s 0 -c 0
sudo python3 ./tools/fuzz_probe.py -c 0 -s 0 -d e1000 -p 50 -m dma
```

## Build Device Model
### First Stage Model
Create a S2E project
```
python3 ./tools/create-s2e-project.py -d <DEV> -v <VID> -p <PID> --subvid <SUBVID> --subpid <SUBPID> --cls <ClassID> [--pio_bar <id:range>]
```
Then go to **s2e/projects**
```
./run-s2e.sh <DEV>
# After finishing running
cd <DEV>
sudo ./get_result.sh
python3 <PROJ_ROOT>/tools/generate_probe_model.py -v <VID> -p <PID> -n <DEV>  >  <HWMODEL_xxx.h>
```
### Second Stage Model
Second Stage perform one profiling run to get the DMA register and static analysis to generate a model for post-probing fuzzing
```
sudo python3 <PROJ_ROOT>/tools/generate_postprobing_model.py --file <HWMODEL_xxx.h> --bc <xxx.bc> --name <xxx> --profile_dma --verbose
```

### Insert Model into the Database
go to **afl-proxy/aplib/hw_model.cpp** to register the devide model. Examples can be found in this file.

## Cite

```
@INPROCEEDINGS{10179293,
  author={Wu, Yilun and Zhang, Tong and Jung, Changhee and Lee, Dongyoon},
  booktitle={2023 IEEE Symposium on Security and Privacy (SP)}, 
  title={DevFuzz: Automatic Device Model-Guided Device Driver Fuzzing}, 
  year={2023},
  volume={},
  number={},
  pages={3246-3261},
  keywords={Privacy;Operating systems;Linux;Computer bugs;Fuzzing;Universal Serial Bus;Device drivers},
  doi={10.1109/SP46215.2023.10179293}}
```