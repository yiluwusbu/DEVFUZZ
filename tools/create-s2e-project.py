#!/usr/bin/python3

import os
import argparse
from common import env_dir

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("-d", "--dev", type=str, required=True)
    parser.add_argument("-v", "--vid", type=str, required=True, help="Vendor ID of the device")
    parser.add_argument("-p", "--pid", type=str, required=True, help="Product ID of the device")
    parser.add_argument("--subvid", type=str, default="0x0", help="Sub Vendor ID of the device")
    parser.add_argument("--subpid", type=str, default="0x0", help="Sub Product ID of the device")
    parser.add_argument("-c", "--cls", type=str, default="0xff000000", help="Class of the device")
    parser.add_argument('--pio_bar', type=str, action='append', help="PIO Bar: [id]:[range]")
    args = parser.parse_args()
    script = env_dir() + "/tools/shell_scripts/create-s2e-project.sh"
    projs_dir = env_dir() + "/s2e/projects"
    os.system(f"{script} {args.dev} {args.vid} {args.pid} {args.subvid} {args.subpid} {args.cls}")
    if args.pio_bar is not None:
        for id_range in args.pio_bar:
            vals = id_range.split(":")
            bar = vals[0]
            length = vals[1]
            key="bar" +bar+"type"
            print(f"Setting {key} to 1")
            os.system(f"sed -i s/{key}=0/{key}=1/g {projs_dir}/{args.dev}/s2e-config.lua")
            os.system(f"sed -i s/bar{bar}range=0xfff80000/bar{bar}range={length}/g {projs_dir}/{args.dev}/s2e-config.lua")

if __name__ == "__main__":
    main()
    
