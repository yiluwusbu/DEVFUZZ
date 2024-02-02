#!/usr/bin/python3

import argparse
import subprocess
import os
from common import env_dir

SFP_SCRIPT=env_dir() + "/tools/shell_scripts/test-probe.sh"

def mode_to_int(mode):
  if mode == "baseline":
    return 1
  elif mode == 'fuzz':
    return 2
  elif mode == "no_fuzz":
    return 3
  else:
    raise Exception("Unknown mode")


def parse_args():
  parser = argparse.ArgumentParser()
  parser.add_argument('--dryrun', action='store_true')
  parser.add_argument('-s', '--shmid', type=int, help="SHMEM ID for AFL - DEVFUZZ communication", required=True)
  parser.add_argument('-c', '--core', type=int, help="CPU core id to pin the QEMU", required=True)
  parser.add_argument('-m', '--mode', type=str, choices=["baseline", "fuzz", "custom"], help="baseline: no fuzzing, fuzz: model based fuzzing (mmio)", required=True)
  parser.add_argument('-d', '--device', type=str, help="Name of the device, i.e. linux driver module name for the device. Use 'test' for dummy device", required=True)
  parser.add_argument('-p', '--prob', type=int, help="Probability for using the AFL instead of the model", default=10)
  parser.add_argument('-q', '--no_console', action='store_true', default=False, help="Don't Display console for qemu")

  args = parser.parse_args()
  args.mode = mode_to_int(args.mode)
  return args

def run(args):
  console = "no_console" if args.no_console else "console"
  qemu_cmd = f"sudo taskset -c {args.core} {SFP_SCRIPT} {args.shmid} {console} {args.mode} {args.device} {args.prob}"
  if args.dryrun:
    print(qemu_cmd)
  else:
    os.system(qemu_cmd)

def main():
  args = parse_args()
  run(args)

if __name__ == "__main__":
  main()