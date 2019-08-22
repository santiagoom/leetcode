import os, sys
import shutil
from shutil import copyfile
from shutil import copytree

# win true
# flag = True

# mac false
flag = False

if flag:
    # win path
    home_path = "D:/repos/leetcode-zero"
else:
    # mac path
    home_path = "/Users/tianm/repos/leetcode-zero/"

leetcode_path = "/Users/tianm/repos/leetcode/"

java_path = home_path + "algorithms/java/src/"
cpp_path = home_path + "algorithms/cpp/"
python_path = home_path + "algorithms/python/"

dst_java_path = leetcode_path + "algorithms/java/src/"
dst_cpp_path = leetcode_path + "algorithms/cpp/"
dst_python_path = leetcode_path + "algorithms/python/"

readme_path = home_path + "readme.md"
dst_readme_path = leetcode_path + "readme.md"

to_leet_record = home_path + "record_to_leet.txt"


def copy2leet():
    with open(to_leet_record, encoding='utf-8', mode='r') as f:
        records = f.readlines()

    copyfile(readme_path, dst_readme_path)

    for record in records:
        record = record[:-1]
        print(record)
        solution_cpp = os.path.join(cpp_path, record)
        solution_py = os.path.join(python_path, record)
        solution_java = os.path.join(java_path, record)

        dst_solution_cpp = os.path.join(dst_cpp_path, record)
        dst_solution_py = os.path.join(dst_python_path, record)
        dst_solution_java = os.path.join(dst_java_path, record)

        if not os.path.exists(dst_solution_cpp):
            os.makedirs(dst_solution_cpp)
        if not os.path.exists(dst_solution_py):
            os.makedirs(dst_solution_py)
        if not os.path.exists(dst_solution_java):
            os.makedirs(dst_solution_java)

        if os.path.exists(solution_cpp):
            for so in os.listdir(solution_cpp):
                if (so.startswith("So")):
                    solution = os.path.join(solution_cpp, so)
                    dst_solution = os.path.join(dst_solution_cpp, so)
                    copyfile(solution, dst_solution)

        if os.path.exists(solution_py):
            for so in os.listdir(solution_py):
                if (so.startswith("So")):
                    solution = os.path.join(solution_py, so)
                    dst_solution = os.path.join(dst_solution_py, so)
                    copyfile(solution, dst_solution)

        if os.path.exists(solution_java):
            for so in os.listdir(solution_java):
                if (so.startswith("So")):
                    solution = os.path.join(solution_java, so)
                    dst_solution = os.path.join(dst_solution_java, so)
                    copyfile(solution, dst_solution)


if __name__ == "__main__":
    copy2leet()
