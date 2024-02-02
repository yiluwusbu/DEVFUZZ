#!/usr/bin/python3

import subprocess
import argparse
from common import env_dir
import os
import re
import time

def analyze(fn_wlog, fn_klog):
    # store the value to register mapping
    addr2reg = {}
    reg_write_cnt = {}
    # process qemu-w.log
    fh_wlog = open(fn_wlog, 'r')
    Lines = fh_wlog.readlines()

    for line in Lines:
        line = line.strip()
        loc = line.find("INFO:write")
        if loc != -1:
            line = line[loc:]
            arr=re.split(r" |=",line)
            #print("processing:" + line)
            reg=int(arr[6],16);
            # if reg not in reg_write_cnt.keys():
            #     reg_write_cnt[reg] = 0
            # else:
            #     reg_write_cnt[reg] += 1
            val=int(arr[7],16)
            if val in addr2reg.keys():
                addr2reg[val].add(reg)
            else:
                addr2reg[val] = {reg}

    #for k in addr2reg.keys():
    #    print(k, addr2reg[k])
    print("closing f1")
    fh_wlog.close()
    print("closed f1")
    # process kvm-trace.log
    fh_klog = open(fn_klog, 'r')
    Lines = fh_klog.readlines()

    dmaaddrs=[]
    top_halfs=[]
    bottom_halfs=[]
    for line in Lines:
        line = line.strip()
        r = re.search("kvm_hypercall: nr", line)
        if r:
            arr = re.split(r" ",line)
            if (arr[-1]!="0x0" and arr[-7] == "0x1"):
                addr = int(arr[-1],16)
                sz = int(arr[-3],16)
                dmaaddrs.append((addr, sz))
                th = addr >> 16
                bh = addr & 0x0000ffff
                top_halfs.append((th, sz))
                bottom_halfs.append((bh, sz))
                
    fh_klog.close()
    code = ""
    print("Register, DMA Buffer Address")
    for (a, sz) in dmaaddrs:
        for k in addr2reg.keys():
            if ((a<=k) and ((k-a)<4096)):
                all_regs = [hex(x) for x in addr2reg[k]]
                print(all_regs)
                print("=>",hex(a))
                code += "model->setDMAReg(" + all_regs[0] + ", " + hex(sz) + ");\n";

    for (a, sz) in top_halfs:
        for k in addr2reg.keys():
            if ( a == k ):
                all_regs = [hex(x) for x in addr2reg[k]]
                print(all_regs)
                print("=>",hex(a))
                code += "model->setDMATopHalfReg(" + all_regs[0] + ", " + hex(sz) + ");\n";
    for (a, sz) in bottom_halfs:
        for k in addr2reg.keys():
            if ( a == k ):
                all_regs = [hex(x) for x in addr2reg[k]]
                print(all_regs)
                print("=>",hex(a))
                code += "model->setDMABottomHalfReg(" + all_regs[0] + ", " + hex(sz) + ");\n";

    print("-------------DMA Register Code-------------------")
    print(code)
    return code
            

def profile(dev):
    scripts_dir = env_dir() + "/afl-proxy/stage2-dynamic-analysis/"
    os.system("sudo " + scripts_dir + "run-after-sfp.sh") 
    listener = "sudo " + scripts_dir + "run-before-sfp.sh &"
    print(listener)
    os.system(listener)
    time.sleep(1)
    sfp = env_dir() + "/tools/shell_scripts/run-profile.sh"
    qemu_cmd = f"sudo {sfp} 0 console {dev}"
    print("Waiting for profile run to finish...")
    print(qemu_cmd)
    subprocess.Popen("exec " + qemu_cmd, shell=True, stdout=subprocess.DEVNULL)
    time.sleep(30)
    os.system("sudo kill -9 $(cat vm-testing-0.pid)")
    os.system("sudo kill -9 $(ps aux | grep run-before-sfp | awk '{print $2}')")
    os.system("sudo " + scripts_dir + "run-after-sfp.sh") 
    
    print("done!")
    return analyze("vm-testing-0.log", "kvm-trace.log")

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-d', '--dev', type=str, required=True)
    parser.add_argument('-a', '--analyze', action="store_true")
    args = parser.parse_args()
    if args.analyze:
        analyze("vm-testing-0.log", "kvm-trace.log")
    else:
        profile(args.dev)

if __name__ == "__main__":
    main()