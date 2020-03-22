import os
import sys
import pyutils as u


def funcs_():
    with open("leetcode_1127.md") as  f:
        lines = f.readlines()

    for line in lines[3:]:
        parts = line.split('|')
        num = parts[1]
        title = parts[2]
        left_pos = title.index('[')
        right_pos = title.index(']')
        title = title[left_pos+1:right_pos]
        msg = "## {}-{}\n".format(num, title)
        u.printf(msg)
        with open("1127.md",mode='a',encoding='utf8') as f:
            f.write(msg)

    pass


def run():
    if (len(sys.argv) != 1):
        print("args error ...")
        sys.exit(0)

    funcs_()


if __name__ == "__main__":
    run()
