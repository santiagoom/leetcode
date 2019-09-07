import os
from datetime import datetime


def files_traversal(path):
    statinfo_start = os.stat(".gitignore")

    with open(".gitignore", mode='r') as f:
        contents = f.readlines()

    ignores = []
    for each in contents:
        if not each.startswith("#"):
            ignores.append(each[:-1])

    for root, dirs, files in os.walk(path):
        for file in files:
            file_name = os.path.join(root, file)
            file_size = os.stat(file_name).st_size / (1024 ** 2)
            file_name = file_name[2:]
            if (file_size > 1.0) and file_name not in ignores:
                with open(".gitignore", mode='a', encoding='utf8') as f:
                    file_size = "# {:.2f}M".format(file_size)
                    f.write(file_size + "\n")
                    f.write(file_name + "\n")
                    print(file_size)
                    print(file_name)

    statinfo_end = os.stat(".gitignore")
    if not (statinfo_start.st_mtime == statinfo_end.st_mtime):
        with open(".gitignore", mode='a', encoding='utf8') as f:
            f.write("# {}".format(datetime.now()) + "\n\n")


if __name__ == "__main__":
    root_path = "./"
    res = files_traversal(root_path)
