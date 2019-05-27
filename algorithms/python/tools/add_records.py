import os, sys

# win true
# flag = True

# mac false
flag = False

if flag:
    # win path
    home_path = "D:/repos/leetcode-root"
else:
    # mac path
    home_path = "/Users/tianm/repos/leetcode-root"

java_path = home_path + "/algorithms/java/src/"
cpp_path = home_path + "/algorithms/cpp/"
python_path = home_path + "/algorithms/python/"
readme_path = home_path + "/README.md"

record_txt = home_path + "/RECORD.txt"
record_path = home_path + "/RECORD.md"


def add_java_records():
    with open(record_txt) as file:
        records = file.readlines()

    head = '''
| # | Title | OF | Self | AC | DF |
|---| ----- | -------- | ---- | ---------- | ---------- |
'''
    record_file = open(record_path, "w")
    record_file.write(head)
    for problem in records:
        print(problem[:-1])
        problem = problem[:-1]
        pieces = problem.split("_")
        record_num = pieces[1]
        problem_num = pieces[2]

        with open(readme_path) as file:
            readme_records = file.readlines()

        for record in readme_records[3:]:
            slices = record.split("|")
            if (slices[1] == problem_num):
                new_title = "[" + slices[1] + " " + slices[2][1:]
                break

        problem_java = os.path.join(java_path, problem)
        solution_java = ""
        try:
            for solution in os.listdir(problem_java):
                # print(problem_java)
                if solution.startswith("So"):
                    abs = os.path.join(problem_java, solution)

                    if flag:
                        solution_java = "[Java](." + abs[22:] + ")"
                        solution_java = solution_java.replace("\\", "/")
                    else:
                        solution_java = "[Java](." + abs[32:] + ")"
                        solution_java = solution_java.replace("\\", "/")

                    # print(solution_java)
        except Exception as e:
            # print(e)
            pass
        problem_python = os.path.join(python_path, problem)
        solution_python = ""
        try:
            for solution in os.listdir(problem_python):
                abs = os.path.join(problem_python, solution)
                if flag:
                    solution_python = "[Python](." + abs[22:] + ")"
                    solution_python = solution_python.replace("\\", "/")
                else:
                    solution_python = "[Python](." + abs[32:] + ")"
                    solution_python = solution_python.replace("\\", "/")
                # print(solution_python)
        except Exception as e:
            # print(e)
            pass

        problem_cpp = os.path.join(cpp_path, problem)

        solution_cpp = ""
        try:
            for solution in os.listdir(problem_cpp):
                abs = os.path.join(problem_cpp, solution)
                if flag:
                    solution_cpp = "[C++](." + abs[32:] + ")"
                    solution_cpp = solution_cpp.replace("\\", "/")
                else:
                    solution_cpp = "[C++](." + abs[32:] + ")"
                    solution_cpp = solution_cpp.replace("\\", "/")
        except Exception as e:
            pass
            # print(e)

        if solution_python == "" and solution_cpp == "" and solution_java != "":
            output = "|" + record_num + "|" + new_title + "|" + slices[
                3] + "|" + solution_java + "" + solution_python + "|" + \
                     slices[4] + slices[
                         5] + "|" + slices[6] + "|"
        elif solution_python != "" and solution_cpp == "" and solution_java != "":
            output = "|" + record_num + "|" + new_title + "|" + slices[
                3] + "|" + solution_java + ", " + solution_python + "|" + \
                     slices[4] + slices[
                         5] + "|" + slices[6] + "|"
        elif solution_python == "" and solution_cpp != "" and solution_java != "":
            output = "|" + record_num + "|" + new_title + "|" + slices[
                3] + "|" + solution_java + ", " + solution_cpp + "|" + \
                     slices[4] + slices[
                         5] + "|" + slices[6] + "|"
        elif solution_python != "" and solution_cpp == "" and solution_java == "":
            output = "|" + record_num + "|" + new_title + "|" + slices[
                3] + "|" + solution_python + "|" + \
                     slices[4] + slices[
                         5] + "|" + slices[6] + "|"

        # print(output)
        record_file.write(output + "\n")


def generate_folders(lists):
    with open(record_txt) as file:
        records = file.readlines()

    current = records[-1][:-1]
    print(current)

    for each in lists:
        if (each == 1):
            java_dir = java_path + current

            content = '''
public class Solutions {
	public static void main(String[] args) {
	    Solution so = new Solution();
	    
	}
}

class Solution{

}
'''
            if not os.path.exists(java_dir):
                os.mkdir(java_dir)
            solutison_java = os.path.join(java_dir, "Solutions.java")
            with open(solutison_java, "a") as file:
                file.write("package " + current + ";\n")
                file.write(content)

        if (each == 2):
            python_dir = python_path + current
            if not os.path.exists(python_dir):
                os.mkdir(python_dir)
            solutison_python = os.path.join(python_dir, "Solutions.py")
            with open(solutison_python, "a") as file:
                file.write("")

        if (each == 3):
            cpp_dir = cpp_path + current
            if not os.path.exists(cpp_dir):
                os.mkdir(cpp_dir)
            solutison_cpp = os.path.join(cpp_dir, "Solutions.cpp")
            with open(solutison_cpp, "a") as file:
                file.write("")


def Run():
    if (len(sys.argv) != 1):
        print("args error ...")
        sys.exit(0)

    # lists = [1, 2, 3]
    # lists = [1]
    # generate_folders(lists)

    # add_java_records()


if __name__ == "__main__":
    Run()
