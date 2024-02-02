#!/usr/bin/python3

import os
import argparse
from common import env_dir

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("-d", "--dev", type=str, required=True)
    parser.add_argument("-c", "--no_check", action="store_true", default=True)
    args = parser.parse_args()
    root = env_dir()
    proj_dir = root + "/s2e/projects/" + args.dev
    
    # check existence of project name
    if not os.path.exists(proj_dir):
        raise Exception("Project path doesn't exist, please create the project first")
    
    # launch status checker
    checker = proj_dir + "/check_ok.sh &"
    os.system("sudo " + checker)
    launcher = proj_dir + "/launch-s2e.sh"
    os.system("sudo " + launcher)
    os.system("sudo kill -9 $(ps aux | grep check_ok.sh | awk '{print $2}')")

if __name__ == "__main__":
    main()