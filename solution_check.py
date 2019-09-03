import os
from datetime import datetime


def files_traversal(path):
    statinfo_start = os.stat(".gitignore")

    for root, dirs, files in os.walk(path):
        for file in files:
            file_name = os.path.join(root, file)
            file_size = os.stat(file_name).st_size / (1024)
            if(file.startswith("So")):
            # if (file_size > 1.0):
            #     file_size = "# {:.2f}M".format(file_size)
                print(file_size)
                print(file_name)


if __name__ == "__main__":
    root_path = "./"
    res = files_traversal(root_path)
