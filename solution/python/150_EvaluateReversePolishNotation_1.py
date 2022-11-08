from typing import List
from utils import *
import collections


class Solution_150_EvaluateReversePolishNotation_1:
    def evalRPN(self, tokens: List[str]) -> int:

        operations = {
            "+": lambda a, b: a + b,
            "-": lambda a, b: a - b,
            "/": lambda a, b: int(a / b),
            "*": lambda a, b: a * b
        }

        current_position = 0

        while len(tokens) > 1:

            # Move the current position pointer to the next operator.
            while tokens[current_position] not in "+-*/":
                current_position += 1

            # Extract the operator and numbers from the list.
            operator = tokens[current_position]
            number_1 = int(tokens[current_position - 2])
            number_2 = int(tokens[current_position - 1])

            # Calculate the result to overwrite the operator with.
            operation = operations[operator]
            tokens[current_position] = operation(number_1, number_2)

            # Remove the numbers and move the pointer to the position
            # after the new number we just added.
            tokens.pop(current_position - 2)
            tokens.pop(current_position - 2)
            current_position -= 1

        return tokens[0]


if __name__ == "__main__":
    nums = ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
    so = Solution_150_EvaluateReversePolishNotation_1()
    res = so.evalRPN(nums)
    print(res)
