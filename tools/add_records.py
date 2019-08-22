import os, sys

# win true
# flag = True

# mac false
flag = False

if flag:
    # win path
    home_path = "D:/repos/leetcode_zero"
else:
    # mac path
    home_path = "/Users/tianm/repos/leetcode_zero"

java_path = home_path + "/algorithms/java/src/"
cpp_path = home_path + "/algorithms/cpp/"
cmake_path = home_path + "/algorithms/"
python_path = home_path + "/algorithms/python/"
readme_path = home_path + "/leetcode_1127.md"

record_txt = home_path + "/record.txt"
to_leet_record = home_path + "/record_to_leet.txt"
record_path = home_path + "/readme.md"

JAVA_HEADER = '''
public class %s {
	public static void main(String[] args) {
	    %s so = new %s();

	}
}

class %s {

}
'''

CPP_HEADER = '''
#include <iostream>

using namespace std;

class Solution {

};

int main() {
    auto *so = new Solution();
    cout << "new file!" << endl;
    return 0;
}
'''

CMakeLists = '''cmake_minimum_required(VERSION 3.14)
project(CXX)

set(CMAKE_CXX_STANDARD 14)

'''


def add_java_records(isleet=False):
    if isleet:
        path = to_leet_record
    else:
        path = record_txt
    with open(path) as file:
        records = file.readlines()
    # print(records)

    ahead = """
# Leetcode Solutions   
**Reference**
- [Discuss](https://leetcode.com/discuss/)
- [Articles](https://leetcode.com/articles/)

(*) means that you need a LeetCode subscription.
 
"""
    # - [GeeksforGeeks](https: // www.geeksforgeeks.org /)

    head = '''
| # | Title | Solution | Difficulty |
|---| ----- | -------- | ---- |
'''
    record_file = open(record_path, "w")
    record_file.write(ahead)
    record_file.write(head)
    for problem in records:
        print(problem[:-1])
        problem = problem[:-1]
        pieces = problem.split("_")
        print(pieces)
        # record_num = pieces[1]
        problem_num = pieces[1]

        with open(readme_path) as file:
            readme_records = file.readlines()

        for record in readme_records[3:]:
            slices = record.split("|")
            # print(slices)
            # print(slices[1])
            # print(problem_num)
            if (slices[1] == problem_num):
                # new_title = "[" + slices[1] + " " + slices[2][1:]
                record_num = problem_num
                print("record_num: ", record_num)
                new_title = "[" + slices[2][1:]
                break

        problem_java = os.path.join(java_path, problem)
        solution_java = ""
        try:
            for solution in os.listdir(problem_java):
                # print(problem_java)
                if solution.startswith("So"):
                    abs = os.path.join(problem_java, solution)

                    if flag:
                        solution_java = " [Java](." + abs[22:] + ")"
                        solution_java = solution_java.replace("\\", "/")
                    else:
                        solution_java = " [Java](." + abs[32:] + ")"
                        solution_java = solution_java.replace("\\", "/")

                    # print(solution_java)
        except Exception as e:
            pass

        problem_python = os.path.join(python_path, problem)
        solution_python = ""
        try:
            for solution in os.listdir(problem_python):
                if solution.startswith("So"):
                    abs = os.path.join(problem_python, solution)
                    if flag:
                        solution_python = "[Python](." + abs[22:] + ")"
                        solution_python = solution_python.replace("\\", "/")
                    else:
                        solution_python = "[Python](." + abs[32:] + ")"
                        solution_python = solution_python.replace("\\", "/")
                    # print(solution_python)
        except Exception as e:
            pass

        problem_cpp = os.path.join(cpp_path, problem)
        solution_cpp = ""
        try:
            for solution in os.listdir(problem_cpp):
                if solution.startswith("So"):
                    abs = os.path.join(problem_cpp, solution)
                    if flag:
                        solution_cpp = "[C++](." + abs[32:] + ")"
                        solution_cpp = solution_cpp.replace("\\", "/")
                    else:
                        solution_cpp = "[C++](." + abs[32:] + ")"
                        solution_cpp = solution_cpp.replace("\\", "/")
        except Exception as e:
            pass

        output = ""
        # cpp and python and java
        if solution_python != "" and solution_cpp != "" and solution_java != "":
            output = "|" + record_num + "|" + new_title + "|" + solution_cpp + ", " + solution_python + "," + solution_java + "|" + \
                     slices[6] + "|"

        # cpp and java
        if solution_python == "" and solution_cpp != "" and solution_java != "":
            output = "|" + record_num + "|" + new_title + "|" + solution_cpp + "," + solution_java + "|" + \
                     slices[6] + "|"

        # cpp and python
        if solution_python != "" and solution_cpp != "" and solution_java == "":
            output = "|" + record_num + "|" + new_title + "|" + solution_cpp + ", " + solution_python + "|" + \
                     slices[6] + "|"

        # cpp
        if solution_python == "" and solution_cpp != "" and solution_java == "":
            output = "|" + record_num + "|" + new_title + "|" + solution_cpp + "|" + \
                     slices[6] + "|"

        # python and java
        if solution_python != "" and solution_cpp == "" and solution_java != "":
            output = "|" + record_num + "|" + new_title + "|" + solution_python + "," + solution_java + "|" + \
                     slices[6] + "|"

        print(output)
        record_file.write(output + "\n")


def generate_folders_all(lists):
    with open(record_txt) as file:
        records = file.readlines()

    # current = records[-1][:-1]
    # print(current)

    for record in records:
        current = record[:-1]
        for each in lists:
            if (each == 1):
                java_dir = java_path + current

                if not os.path.exists(java_dir):
                    os.mkdir(java_dir)
                solutison_java = os.path.join(java_dir, "Solutions.java")
                if not os.path.exists(solutison_java):
                    with open(solutison_java, "w") as file:
                        file.write("package " + current + ";\n")
                        file.write(JAVA_HEADER.format())

            if (each == 2):
                python_dir = python_path + current
                if not os.path.exists(python_dir):
                    os.mkdir(python_dir)
                solutison_python = os.path.join(python_dir, "Solutions.py")
                if not os.path.exists(solutison_python):
                    with open(solutison_python, "w") as file:
                        file.write("")

            if (each == 3):
                cpp_dir = cpp_path + current
                if not os.path.exists(cpp_dir):
                    os.mkdir(cpp_dir)
                solutison_cpp = os.path.join(cpp_dir, "Solutions.cpp")
                if not os.path.exists(solutison_cpp):
                    with open(solutison_cpp, "w") as file:
                        file.write("")


def generate_folders_individual_current(lists):
    with open(record_txt) as file:
        records = file.readlines()

    current = records[-1][:-1]
    print(current)

    for each in lists:
        if (each == 1):
            java_dir = java_path + current

            if not os.path.exists(java_dir):
                os.mkdir(java_dir)
            solutison_java_std = os.path.join(java_dir, current + "_std.java")
            solutison_java_practise = os.path.join(java_dir, current + "_practise.java")
            solutison_java_std_debug = os.path.join(java_dir, current + "_std_debug.java")
            if not os.path.exists(solutison_java_std):
                with open(solutison_java_std, "w") as file:
                    file.write("package " + current + ";\n")
                    file.write(JAVA_HEADER % (
                        current + "_std", current + "_std_", current + "_std_", current + "_std_"))
            if not os.path.exists(solutison_java_practise):
                with open(solutison_java_practise, "w") as file:
                    file.write("package " + current + ";\n")
                    file.write(JAVA_HEADER % (
                        current + "_practise", current + "_practise_", current + "_practise_", current + "_practise_"))
            if not os.path.exists(solutison_java_std_debug):
                with open(solutison_java_std_debug, "w") as file:
                    file.write("package " + current + ";\n")
                    file.write(JAVA_HEADER % (
                        current + "_std_debug", current + "_std_debug_", current + "_std_debug_",
                        current + "_std_debug_"))

        if (each == 2):
            python_dir = python_path + current
            if not os.path.exists(python_dir):
                os.mkdir(python_dir)
            solutison_python_std = os.path.join(python_dir, current + "_std.py")
            solutison_python_std_debug = os.path.join(python_dir, current + "_std_debug.py")
            solutison_python_practise = os.path.join(python_dir, current + "_practise.py")
            if not os.path.exists(solutison_python_std):
                with open(solutison_python_std, "w") as file:
                    file.write("")
            if not os.path.exists(solutison_python_std_debug):
                with open(solutison_python_std_debug, "w") as file:
                    file.write("")
            if not os.path.exists(solutison_python_practise):
                with open(solutison_python_practise, "w") as file:
                    file.write("")

        if (each == 3):
            cpp_dir = cpp_path + current
            if not os.path.exists(cpp_dir):
                os.mkdir(cpp_dir)
            solutison_cpp_std = os.path.join(cpp_dir, current + "_std.cpp")
            solutison_cpp_std_debug = os.path.join(cpp_dir, current + "_std_debug.cpp")
            solutison_cpp_practise = os.path.join(cpp_dir, current + "_practise.cpp")
            solutison_cpp_CMakeLists = os.path.join(cpp_dir, "CMakeLists.txt")
            solutison_info = os.path.join(cpp_dir, "info.txt")

            cpp_CMakeLists = os.path.join(cmake_path, "CMakeLists.txt")
            with open(cpp_CMakeLists, "r") as file:
                lastline = file.readlines()[-1]
                last_id = lastline[lastline.index("/") + 1:-2]
                # print(last_id)
                if (last_id != current):
                    with open(cpp_CMakeLists, "a") as file:
                        file.write("add_subdirectory(cpp/" + current + ")\n")

            if not os.path.exists(solutison_cpp_std):
                with open(solutison_cpp_std, "w") as file:
                    file.write(CPP_HEADER)
            if not os.path.exists(solutison_cpp_std_debug):
                with open(solutison_cpp_std_debug, "w") as file:
                    file.write(CPP_HEADER)
            if not os.path.exists(solutison_cpp_practise):
                with open(solutison_cpp_practise, "w") as file:
                    file.write(CPP_HEADER)
            if not os.path.exists(solutison_cpp_CMakeLists):
                with open(solutison_cpp_CMakeLists, "w") as file:
                    file.write(CMakeLists)
                    file.write("add_executable(" + current + "_std " + current + "_std.cpp)\n")
                    file.write("add_executable(" + current + "_std_debug " + current + "_std_debug.cpp)\n")
                    file.write("add_executable(" + current + "_practise " + current + "_practise.cpp)\n")
                    file.write("add_executable(" + "Solutions" + current[:4] + " Solutions.cpp)\n")
            if not os.path.exists(solutison_info):
                with open(solutison_info, "w") as file:
                    file.write("")


def generate_folders_individual_so(lists):
    with open(record_txt) as file:
        records = file.readlines()

    current = records[-1][:-1]
    print(current)

    for each in lists:
        if (each == 1):
            java_dir = java_path + current

            if not os.path.exists(java_dir):
                os.mkdir(java_dir)
            solutison_java = os.path.join(java_dir, "Solutions.java")
            if not os.path.exists(solutison_java):
                with open(solutison_java, "w") as file:
                    file.write("package " + current + ";\n")
                    file.write(JAVA_HEADER % ("Solutions", "Solution", "Solution", "Solution"))

        if (each == 2):
            python_dir = python_path + current
            if not os.path.exists(python_dir):
                os.mkdir(python_dir)
            solutison_python = os.path.join(python_dir, "Solutions.py")
            if not os.path.exists(solutison_python):
                with open(solutison_python, "w") as file:
                    file.write("")

        if (each == 3):
            cpp_dir = cpp_path + current
            if not os.path.exists(cpp_dir):
                os.mkdir(cpp_dir)
            solutison_cpp = os.path.join(cpp_dir, "Solutions.cpp")
            if not os.path.exists(solutison_cpp):
                with open(solutison_cpp, "w") as file:
                    file.write(CPP_HEADER)


def Run():
    if (len(sys.argv) != 1):
        print("args error ...")
        sys.exit(0)

    list_current = [2,3]
    generate_folders_individual_current(list_current)
    #
    list_so = [3]
    generate_folders_individual_so(list_so)

    add_java_records(True)
    # add_java_records(False)


if __name__ == "__main__":
    Run()
