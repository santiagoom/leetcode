
from typing import List  
from utils import *
                    
def evalRPN(self, tokens: List[str]) -> int:

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
        if operator == "+":
            tokens[current_position] = number_1 + number_2
        elif operator == "-":
            tokens[current_position] = number_1 - number_2
        elif operator == "*":
            tokens[current_position] = number_1 * number_2
        else:
            tokens[current_position] = int(number_1 / number_2)
        
        # Remove the numbers and move the pointer to the position
        # after the new number we just added.
        tokens.pop(current_position - 2)
        tokens.pop(current_position - 2)
        current_position -= 1
        
    return tokens[0]

if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 26
    s = "aa"
    arrays = [[1, 2, 3], [4, 5, 6]]
    print(arrays)
                    