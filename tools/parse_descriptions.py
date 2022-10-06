import os


def func():

    # path = "../solution/notebook/Descriptions_1.md"
    path = "../solution/notebook/Descriptions_2.md"
    with open(path, mode="r") as f:
        content = f.read()


    cpp_path = "solution/cpp/"
    if not os.path.exists(cpp_path):
        os.makedirs(cpp_path)
    java_path = "solution/java/"
    if not os.path.exists(java_path):
        os.makedirs(java_path)
    py_path = "solution/python/"
    if not os.path.exists(py_path):
        os.makedirs(py_path)

    problems = content.split("##")

    for solutions in problems[:]:

        solutions = solutions.split("```")
        print(solutions)
        title = solutions[0].strip()



        count = 0
        for i, solution in enumerate(solutions):
            if i == 0:
                continue
            if len(solution) > 5:
                count += 1
                if solution.find("public ") > -1:
                    lang = "java"
                    filename = "{}/{}_{}.{}".format(java_path, title, count, lang)
                    with open(filename, mode="w", encoding="utf8") as f:
                        f.write(solution)
                if solution.find("public:") > -1:
                    lang = "cpp"
                    filename = "{}/{}_{}.{}".format(cpp_path,title, count, lang)
                    with open(filename, mode="w", encoding="utf8") as f:
                        f.write(solution)
                if solution.find("def") > -1:
                    lang = "py"
                    filename = "{}/{}_{}.{}".format(py_path, title, count, lang)
                    with open(filename, mode="w", encoding="utf8") as f:
                        f.write(solution)


def run():
    func()


if __name__ == '__main__':
    run()
