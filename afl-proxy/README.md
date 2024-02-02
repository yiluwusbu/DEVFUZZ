AFL Proxy
----------------------
This is AFL proxy(AP). This repo contains a lighweight proxy program(**ap**) launched by AFL.
A library **aplib** used by client to communicate with AP.

<pre>
|--------\    spawn AP process                   IPC with client using
|  AFL    | <------------------> [./ap fuzz.data]<------------------>   QEMU[KVM]
``````^```    create fuzz data         |          /dev/shm/afl-proxy       |
       \                               |                                   |
        \                              |                                   |
         \   code coverage bitmap      | enable perf-pt(PIDX) <------ap_attach_pt(PIDX)
          `--------------------------> |                                vmx_on()
</pre>

At a high level, AP creates a shared memory(**/dev/shm/afl-proxy**) and accepts requests from the real client, QEMU e.g.
Client get fuzz data location through SHM.
The code coverage information is provided by client by explicitly calling **ap_log_pc(uint64_t)** at each basicblock or it could be provided by PT. If using PT, client need to call **ap_attach_pt(PIDX)** to enable PT-monitor in ap.
Also, if PT is used, clients don't have to call ** ap_log_pc** at each basic block thus saving time.
The client program should be linked with aplib.

AP supports two different modes to collect code coverage. One is through explicit call to **ap_log_pc(uint64_t pc)**, another is through PT.

AP relies on Linux **perf** subsystem to collect PT trace.

Second Stage Analysis
---------------
The device model build can be break down into two stage:

1) s2e symbolic execution - produce first device model that can pass probing

2) dynamic analysis to produce PCI bus master support model -- improve first model with DMA support

To run 2nd step, the guest kernel must be patched with **0001-sfp-Add-hypercall-to-let-host-know-dma-buffer-locati.patch**


Installation
---------------

* download AFL from https://github.com/google/AFL.git and compile
* compile afl-proxy and aplib

```
$(afl-proxy): make
```

* download QEMU from https://github.com/lzto/qemu and compile sfpv2-fuzz branch
* prepare rootfs image **TODO**
* prepare target kernel **TODO**

Run AFL proxy
-------------

First, run AP using the following command

```
cd run
./run.sh
```

After AP is launched, start QEMU in another terminal


Coding Style
-------------

use LLVM coding style and run **make indent**

Limitations
------------

- only single core/thread is supported when using PT


APLib Environment Variables
-----------
* **AP_DISABLED**=0,1: disable ap proxy - some device probing logic still works but won't connect to ap for fuzzing
* **AP_DUMP_RW**=0,1,2,3: dump device memory trace, nodump-0/r-1/w-2/rw-3
* **AP_DUMP_FILE**=filename: where to dump trace, default is stdout
* **EXPORT_DEVMEM**=0,1:  export device memory(PCI bar e.g.) through shared memory (/dev/shm/)
* **NO_REDIRECT_READ**=0,1: do not redirect read to AP - 0 redirect - 1 direct
* **SFP_SHMID**=number: add suffix to shm file so that multiple instances can be launched
* **USE_DMA**=0,1: try to support DMA
* **USE_IRQ**=0,non-zero-value-X: generate interrupt every X milliseconds, 0 to disable, this can be overriden by upper layer device model
* **WAITGDB**=0,1: stop and waiting for gdb to attach at launch, useful for debugging aplib

Device Model Generation Through Machine Learning
----------

ML related code is in **ml** and **pylib** directory. To use it, first build python library

```
cd pylib && make
```
You will need to change the qemu launch script path in **launch\_qemu** and **kill\_qemu** function.

Adjust **ml/config** and fitness function for target driver and run **train.py** to get the result in **real\_winner.pkl**.

To run the generated model, use **run.py** script.

Some pre-trained device model is located at [sfp-ml-dev-model-db](sfp-ml-dev-model-db)

Misc
----------
* s2e-tools: tools to convert s2e result to device model, prepare s2e project, check status and upload artifact to model archive server


