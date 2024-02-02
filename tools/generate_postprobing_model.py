#!/usr/bin/python3

import subprocess
import os
import re
from common import env_dir
import argparse
import profile_dma

template='''\
Stage2HWModel * new_stage2_model_<NAME>() {
<MODEL_DEF>
<DMA_REG_DEF>
  return model;
}
'''

def codegen(mdl_file, bc_file, name, run_dma=True, verbose=False):
    analysis_script = env_dir() + "/tools/shell_scripts/static-analysis.sh " + bc_file
    output = ""
    tmpout = ".tmp.pass_output"
    os.system(analysis_script + " >> " + tmpout)
    with open(tmpout, "r") as f:
        output = f.readlines()

    start = 0
    end = 0
    for i, l in enumerate(output):
        if "Stage2 Model Init Code" in l:
            start = i+1
        elif "DONE!" in l:
            end = i
    
    output = output[start:end]
    mdl = ""
    for l in output:
        mdl += "  " + l 
    
    code = re.sub("<MODEL_DEF>", mdl, template)
    code = re.sub("<NAME>", name, code)
    if not run_dma:
        code = re.sub("<DMA_REG_DEF>", "", code)
    else:
        reg_defs = profile_dma.profile(name)
        code = re.sub("<DMA_REG_DEF>", "  "+reg_defs, code)

    print(code)
    with open(mdl_file, 'a') as f:
        f.write(code)
    
    os.system("rm " + tmpout)

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-f', '--file', type=str, help="Code file of the device model", required=True)
    parser.add_argument('-b', '--bc', type=str, help="Bitcode File for the device driver", required=True)
    parser.add_argument('-v', '--verbose', action='store_true', help="Print the generated code to stdout", default=False)
    parser.add_argument('-n', '--name', type=str, help="Name of the device",required=True)
    parser.add_argument('-p', '--profile_dma', help="Run DMA Analysis", action='store_true', default=False)

    args = parser.parse_args()
    codegen(args.file, args.bc, args.name, args.profile_dma, args.verbose)


if __name__ == "__main__":
    main()
