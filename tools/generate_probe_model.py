#!/usr/bin/python3

import re
import io
from common import env_dir
import argparse
import os

template = '''\
///
/// hardware model for <NAME>
/// 2021 Tong Zhang<ztong0001@gmail.com>
/// 2022 Yilun Wu <yiluwu@cs.stonybrook.edu>
///

#include "HWModel.h"

class HWModel_<NAME> : public HWModel {
public:
  HWModel_<NAME>() : HWModel("<NAME>", <VID>, <PID>), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_<NAME>(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > <PROBE_LEN>)
      return 0;
    switch(addr) 
    {
<SM>
    }
    probe_len++;
    return size;
  };
  virtual void write(uint64_t data, uint64_t addr, size_t size) final{};

  virtual void *getUSBDesc() { return nullptr; }

private:
  int probe_len;
};
'''

def generate_code_block(addr, values, stream):
    print("    case(",addr,"):{", file=stream)
    print("    static int cnt;", file=stream)
    cnt = 0
    for v in values:
        size, value = v
        if size==1:
            print("    if (cnt ==",cnt,") *((uint8_t *)dest) =", value, ";", file=stream)
        if size==2:
            print("    if (cnt ==",cnt,") *((uint16_t *)dest) =", value, ";", file=stream)
        if size==4:
            print("    if (cnt ==",cnt,") *((uint32_t *)dest) =", value, ";", file=stream)
        cnt = cnt+1
    print("    cnt++;}", file=stream)

# Using readlines()
def codegen(name, vid, pid, result):
    code_stream = io.StringIO()
    file1 = open(result, 'r')
    Lines = file1.readlines()

    count = 0
    addr = 0
    size = 0
    byte_idx = 0
    data = []

    reg_model = {}

    # Strips the newline character
    for line in Lines:
        line = line.strip()
        r = re.search("mmio",line)
        if r:
            arr1 = re.split("___",line)
            arr2 = re.split("_",arr1[1])
            addr = arr2[0]
            size = int(arr2[2])
            #print(addr, size)
        elif size != 0:
            arr1 = re.split(" ",line)
            data.append(int(arr1[1],16))
            if len(data) == size:
                adata = 0
                for d in data:
                    adata = adata << 8
                    adata += d
                if addr not in reg_model:
                    reg_model[addr] = []
                reg_data = reg_model[addr]
                reg_data.append((size,adata))
                #print(addr, hex(adata))
                data = []
                size = 0

    probe_len = 0
    for addr, reg_data in reg_model.items():
        #print(addr, reg_data)
        probe_len += len(reg_data)
        generate_code_block(addr, reg_data, code_stream)

    state_machine = code_stream.getvalue();
    code_stream.close()
    code = re.sub("<NAME>", name, template)
    code = re.sub("<VID>", vid, code)
    code = re.sub("<PID>", pid, code)
    code = re.sub("<PROBE_LEN>", str(probe_len), code)
    code = re.sub("<SM>", state_machine, code)
    print(code)
    return code


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-v', '--vid', type=str, help="Vendor ID of the device", required=True)
    parser.add_argument('-p', '--pid', type=str, help="Product ID of the device", required=True)
    parser.add_argument('-n', '--name', type=str, help="Name of the device",required=True)

    args = parser.parse_args()
    s2e_proj_dir = env_dir() + "/s2e/projects/" + args.name + "/"
    result_path = s2e_proj_dir + "result.txt"
    codegen(args.name, args.vid, args.pid, result_path)


if __name__ == "__main__":
    main()