import os
import sys
import pyutils as u
from shutil import copy, move


def funcs_():
    # cpp_dir = "/Users/tianm/repos/leetcode-zero/algorithms/cpp"
    cpp_dir = "/Users/tianm/repos/coding-interviews/algorithms/cpp"
    cmake_file_src = "/Users/tianm/repos/lang-tutorial/02-utils/cppUtils/test_utils/CMakeLists.txt"
    flag = "leetcode"
    flag = "coding"
    for root, dirs, files in os.walk(cpp_dir):
        if dirs:
            for dir in dirs:
                cmake_file_dst = os.path.join(root, dir, "CMakeLists.txt")
                solutions_src = os.path.join(root, dir, "Solutions.cpp")
                if os.path.isfile(solutions_src):

                    if flag == "leetcode":
                        if dir.startswith("_"):
                            parts = dir.split("_")
                            print(parts)
                            solutions_dst = os.path.join(root, dir, "Solutions_{}.cpp".format(parts[1]))
                        else:
                            solutions_dst = os.path.join(root, dir, "Solutions_{}.cpp".format(dir))

                    if flag == "coding":
                        parts = dir.split("_")
                        if len(parts) == 2:
                            solutions_dst = os.path.join(root, dir, "Solutions_{}.cpp".format(parts[0]))
                        else:

                            solutions_dst = os.path.join(root, dir, "Solutions_{}_{}.cpp".format(parts[0], parts[1]))
                        pass
                    # print(solutions_dst)
                    os.rename(solutions_src, solutions_dst)
                u.copy(cmake_file_src, cmake_file_dst)

    pass


def run():
    if (len(sys.argv) != 1):
        print("args error ...")
        sys.exit(0)

    funcs_()


if __name__ == "__main__":
    run()
