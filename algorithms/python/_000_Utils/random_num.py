import numpy as np

if __name__ == "__main__":
    print("{",end="")
    for i in range(20):
        num = np.random.randint(10, 50)
        print(num, end=", ")
    print("}")
