from os.path import dirname, abspath

def env_dir():
    f = abspath(__file__)
    return dirname(dirname(f))


if __name__ == "__main__":
    print(env_dir())