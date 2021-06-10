import os, sys

# win true
# flag = True

# mac false
flag = False

if flag:
    # win path
    home_path = "D:/repos/leetcode-zero"
else:
    # mac path
    home_path = "/Users/tianm/repos/leetcode-zero"

records_path = "records.txt"
solution_cpp_path = "/solution/cpp"
solution_python_path = "/solution/python"
solution_java_path = "/solution/java"

record_path = home_path + "/readme.md"
readme_path = "leetcode_1127.md"


def generate_readme():
    with open(records_path) as file:
        records = file.readlines()

    for record in records[len(records):-len(records) - 1:-1]:
        solution_cpp = os.path.join(solution_cpp_path, "{}.cpp".format(record.strip()))
        solution_python = os.path.join(solution_cpp_path, "{}.py".format(record.strip()))

        print(solution_cpp)

    # records = sorted(records, reverse=True)
    # print(records)


def add_records(isleet=False):
    path = records_path
    with open(path) as file:
        records = file.readlines()
    # print(records)

    ahead = """
# Leetcode Solutions   
**Reference**
- [Discuss](https://leetcode.com/discuss/)
- [Articles](https://leetcode.com/articles/)
- [GeeksforGeeks](https://www.geeksforgeeks.org/)

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

    for problem in records[len(records):-len(records) - 1:-1]:
    # for problem in records:
        print(problem[:-1])
        problem = problem[:-1]
        pieces = problem.split("_")
        print(pieces)
        # record_num = pieces[1]
        # problem_num = pieces[1]
        problem_num = pieces[0]

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

        problem_cpp_abs = os.path.join("{}{}/{}.cpp".format(home_path, solution_cpp_path, problem))
        problem_cpp = os.path.join(solution_cpp_path, "{}.cpp".format(problem))
        solution_cpp = "[C++](." + problem_cpp + ")"

        problem_python_abs = os.path.join("{}{}/{}.py".format(home_path, solution_python_path, problem))
        problem_python = os.path.join(solution_python_path, "{}.py".format(problem))
        solution_python = "[Python](." + problem_python + ")"

        output = ""

        if os.path.exists(problem_cpp_abs) and os.path.exists(problem_python_abs):
            output = "|" + record_num + "|" + new_title + "|" + solution_cpp + ", " + solution_python + "|" + \
                     slices[6] + "|"

        if os.path.exists(problem_cpp_abs) and not os.path.exists(problem_python_abs):
            output = "|" + record_num + "|" + new_title + "|" + solution_cpp + "|" + \
                     slices[6] + "|"
        if not os.path.exists(problem_cpp_abs) and os.path.exists(problem_python_abs):
            output = "|" + record_num + "|" + new_title + "|" + solution_python + "|" + \
                     slices[6] + "|"

        # output = ""
        # # cpp and python and java
        # if solution_python != "" and solution_cpp != "" and solution_java != "":
        #     output = "|" + record_num + "|" + new_title + "|" + solution_cpp + ", " + solution_python + "," + solution_java + "|" + \
        #              slices[6] + "|"
        #
        # # cpp and java
        # if solution_python == "" and solution_cpp != "" and solution_java != "":
        #     output = "|" + record_num + "|" + new_title + "|" + solution_cpp + "," + solution_java + "|" + \
        #              slices[6] + "|"
        #
        # # cpp and python
        # if solution_python != "" and solution_cpp != "" and solution_java == "":
        #     output = "|" + record_num + "|" + new_title + "|" + solution_cpp + ", " + solution_python + "|" + \
        #              slices[6] + "|"
        #
        # # cpp
        # if solution_python == "" and solution_cpp != "" and solution_java == "":
        #     output = "|" + record_num + "|" + new_title + "|" + solution_cpp + "|" + \
        #              slices[6] + "|"
        #
        # # python and java
        # if solution_python != "" and solution_cpp == "" and solution_java != "":
        #     output = "|" + record_num + "|" + new_title + "|" + solution_python + "," + solution_java + "|" + \
        #              slices[6] + "|"

        print(output)
        record_file.write(output + "\n")


def Run():
    if (len(sys.argv) != 1):
        print("args error ...")
        sys.exit(0)

    # generate_readme()
    add_records()


if __name__ == "__main__":
    Run()
