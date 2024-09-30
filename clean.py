import os
import shutil


def main():
    for f in os.listdir("tmp"):
        if f == ".gitkeep":
            continue
        ff = os.path.join("tmp", f)
        if os.path.isdir(ff):
            shutil.rmtree(ff)
        else:
            os.remove(ff)


if __name__ == "__main__":
    main()
