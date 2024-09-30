import shutil
import subprocess
import sys
from os import mkdir, path

CC = "sdcc"
SRC = "src"
TMP = "tmp"
OUTPUT = "output"

linked = []


def compileCfile(file: str) -> list[str]:
    needLink: list[str] = [file]
    with open(file, encoding="utf-8") as f:
        for line in f.readlines():
            if not line.startswith('#include "'):
                continue
            target = line.replace("#include", "").strip(' "\n').removesuffix("h") + "c"
            if target in linked:
                continue
            linked.append(target)
            needLink += compileCfile(target)
    print("Compile C file:", file)
    dir = TMP + "/" + path.dirname(file) + "/"
    try:
        mkdir(dir)
    except:
        pass
    proc = subprocess.run(
        [CC, "-I.", "-c", file, "-o", dir],
    )
    if proc.returncode != 0:
        exit(proc.returncode)

    return needLink


def main():

    if not shutil.which(CC):
        print("在 PATH 中找不到 sdcc")
    if not shutil.which("packihx"):
        print("在 PATH 中找不到 packihx")
    if len(sys.argv) < 2:
        print("需要一个参数为入口 C 文件")
        exit(1)
    print("Compile main:", SRC + "/" + sys.argv[1])
    needLink = compileCfile(SRC + "/" + sys.argv[1])
    needLink = ["tmp/" + s[:-1] + "rel" for s in needLink]
    for l in needLink:
        print(l)
    name = sys.argv[1].removesuffix("c")
    subprocess.run([CC] + needLink + ["-o", TMP + "/"])
    with open(OUTPUT + "/" + name + "hex", "wb") as hex:
        subprocess.run(["packihx", TMP + "/" + name + "ihx"], stdout=hex)


if __name__ == "__main__":
    main()
