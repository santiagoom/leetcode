import os, sys

import numpy as np


def topic_format(path):
    with open(path, mode='r') as f:
        lines = f.readlines()
    newLines = []
    for line in lines:
        line = line.replace(".", "")[:-1]
        parts = line.split(' ')
        s = ""
        for i, part in enumerate(parts):
            if (i <= 1):
                s += "_"
            s += part
        newLines.append(s)

    with open("format.txt", mode="w", encoding="utf8") as f:
        for newLine in newLines:
            f.write(newLine + "\n")


def Run():
    if (len(sys.argv) != 1):
        print("args error ...")
        sys.exit(0)

    path = "input.txt"
    topic_format(path)


if __name__ == "__main__":
    Run()
