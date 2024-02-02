#!/usr/bin/python3

import re

def generate_code_block(addr, values):
    print("case(",addr,"):{")
    print("static int cnt;")
    cnt = 0
    for v in values:
        size, value = v
        if size==1:
            print("if (cnt==",cnt,") *((uint8_t *)dest) =", value, ";")
        if size==2:
            print("if (cnt==",cnt,") *((uint16_t *)dest) =", value, ";")
        if size==4:
            print("if (cnt==",cnt,") *((uint32_t *)dest) =", value, ";")
        cnt = cnt+1
    print("cnt++;}")

# Using readlines()
file1 = open('result.txt', 'r')
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

for addr, reg_data in reg_model.items():
    #print(addr, reg_data)
    generate_code_block(addr, reg_data)

