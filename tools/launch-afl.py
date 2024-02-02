#!/usr/bin/python3

from common import env_dir
import argparse
import os

AFL_SCRIPT = env_dir() + "/tools/shell_scripts/run-afl.sh"
SEED_DIR = env_dir() + "/tools/seed"

def parse_args():
  parser = argparse.ArgumentParser()
  parser.add_argument('--dryrun', action='store_true')
  parser.add_argument('-s', '--shmid', type=int, help="SHMEM ID for AFL - DEVFUZZ communication", required=True)
  parser.add_argument('-c', '--core', type=int, help="CPU core id to pin the QEMU", required=True)
  parser.add_argument('-d', '--seed', type=str, help="Directory of the seed files for AFL", default=SEED_DIR)
  args = parser.parse_args()
  return args

def run(args):
  afl_cmd = f"sudo {AFL_SCRIPT} {args.seed} {args.core} {args.shmid} {args.core+1}"
  if args.dryrun:
    print(afl_cmd)
  else:
    os.system(afl_cmd)

def main():
  args = parse_args()
  run(args)

if __name__ == "__main__":
  main()