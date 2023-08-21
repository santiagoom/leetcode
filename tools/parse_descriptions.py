import os


def func():
    # path = "../notebook/Descriptions_1.md"
    # path = "../notebook/Descriptions_2.md"
    # path = "../notebook/Descriptions_3.md"
    # path = "../notebook/Descriptions_4.md"
    path = "../notebook/Descriptions_5.md"
    with open(path, mode="r") as f:
        content = f.read()
    cpp_path = "../solution/cpp/"
    if not os.path.exists(cpp_path):
        os.makedirs(cpp_path)
    java_path = "../solution/java/src"
    if not os.path.exists(java_path):
        os.makedirs(java_path)
    py_path = "../solution/python/"
    if not os.path.exists(py_path):
        os.makedirs(py_path)

    problems = content.split("##")

    cpp_flag = False
    java_flag = False
    py_flag = False

    cpp_flag = True
    java_flag = True
    py_flag = True

    for solutions in problems[1:]:
        solutions = solutions.split("```")
        title = solutions[0].strip()

        solution_number = title[:3]

        specific = [
            "459",
        ]
        if solution_number not in specific:
            continue

        # if int(solution_number) < 171:
        #     continue

        print(solution_number)

        count = 0
        for i, solution in enumerate(solutions):
            if i == 0:
                continue
            if len(solution) > 5:

                count += 1
                if solution.find("public ") > -1:
                    if not java_flag:
                        continue
                    lang = "java"

                    # solution_path = os.path.join(java_path,"Solution_{}".format( title))
                    # if not os.path.exists(solution_path):
                    #     os.makedirs(solution_path)

                    filename = replace_char("{}/_{}_{}.{}".format(java_path, title, count, lang))
                    classname = replace_char("_{}_{}".format(title, count))

                    package = """
                    import java.util.*;
                    import utils.TreeNode;
                    import utils.ListNode;
                    import utils.JavaUtils;
                                            """

                    if solution.find("class Solution") < 0:

                        JAVA_HEADER = '''
%s
                        class %s{
                        %s
                        }
                        public class %s {
                            public static void main(String[] args) {
                                %s so = new %s();
                                 int[] nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
                                                        JavaUtils.print_1d_array(nums);
                                                        int[][] arrays = {{2, 7, 9}, {3, 6, 1}, {7, 4, 2}};
                                                        JavaUtils.print_2d_array(arrays);
                                                
                                                        int target = 26;
                                                        String s = "aa";
                            }
                        }
                        '''

                        with open(filename, mode="w", encoding="utf8") as f:
                            f.write(JAVA_HEADER % (package, "Solution{}".format(classname),
                                                   solution.replace("public class", "class"), classname,
                                                   "Solution{}".format(classname), "Solution{}".format(classname)))
                    else:
                        JAVA_HEADER = '''
                        %s
                                                %s
                                                public class %s {
                                                    public static void main(String[] args) {
                                                        %s so = new %s();
                                                        int[] nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
                                                        JavaUtils.print_1d_array(nums);
                                                        int[][] arrays = {{2, 7, 9}, {3, 6, 1}, {7, 4, 2}};
                                                        JavaUtils.print_2d_array(arrays);
                                                
                                                        int target = 26;
                                                        String s = "aa";
                                                    }
                                                }
                                                '''

                        with open(filename, mode="w", encoding="utf8") as f:
                            f.write(JAVA_HEADER % (package,
                                                   solution.replace("public class", "class").replace("class Solution",
                                                                                                     "class Solution{}".format(
                                                                                                         classname)),
                                                   classname, "Solution{}".format(classname),
                                                   "Solution{}".format(classname)))

                if solution.find("public:") > -1:
                    if not cpp_flag:
                        continue
                    lang = "cpp"
                    filename = replace_char("{}/{}_{}.{}".format(cpp_path, title, count, lang))
                    classname = replace_char("_{}_{}".format(title, count))

                    cpp_head = """
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    """
                    cpp_main = f"""
int main() {{
auto *so = new Solution{classname}();
vector<int> nums{{2, 7, 11, 15}};
int target = 26;
string s = "aa";
vector<vector<int>> arrays;
CppUtils::print(s);
CppUtils::print_1d_vector(nums);
CppUtils::print_2d_vector(arrays);
return 0;
}}
                    """
                    with open(filename, mode="w", encoding="utf8") as f:
                        f.write(cpp_head)
                        f.write(solution.replace("class Solution", "class Solution{}".format(classname)))
                        f.write(cpp_main)
                if solution.find("def") > -1:
                    if not py_flag:
                        continue
                    lang = "py"
                    filename = replace_char("{}/{}_{}.{}".format(py_path, title, count, lang))
                    classname = replace_char("_{}_{}".format(title, count))
                    py_head = """
from typing import List  
from utils import *
import collections
                    """
                    py_main = """
if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
    so = Solution{}()
    s = "aa"
    res = 1
    print(res)
                    """.format(classname)
                    with open(filename, mode="w", encoding="utf8") as f:
                        f.write(py_head)
                        f.write(solution.replace("class Solution:", "class Solution{}:".format(classname)).replace(
                            "class Solution(object):", "class Solution{}:".format(classname)))
                        f.write(py_main)


def replace_char(solution):
    res = solution \
        .replace("(", "_") \
        .replace(")", "") \
        .replace(",", "_") \
        .replace("'", "_") \
        .replace("'", "_") \
        .replace("-", "_") \
        .replace("'", "_")

    return res

    pass


def run():
    func()


if __name__ == '__main__':
    run()
