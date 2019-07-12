import numpy as np


class MyHashSet(object):
    '''
    bug:

    def add if self.s[i] is not None  not self.s[i]
    '''

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.capacity = 8
        self.size = 0
        self.s = [None] * 8
        # self.lf = float(2) / 3
        self.lf = 0.75

    def myhash(self, key):  # can be modified to hash other hashable objects like built in python hash function
        return key % self.capacity

    def add(self, key):
        """
        :type key: int
        :rtype: void
        """
        if float(self.size) / self.capacity >= self.lf:
            self.capacity <<= 1
            ns = [None] * self.capacity
            for i in range(self.capacity >> 1):
                if self.s[i] is not None and self.s[i] != "==TOMBSTONE==":
                    n = self.myhash(self.s[i])
                    while ns[n] is not None:
                        n = (5 * n + 1) % self.capacity
                    ns[n] = self.s[i]
            self.s = ns

        h = self.myhash(key)
        while self.s[h] is not None:
            # print(h)
            if self.s[h] == key:
                return
            h = (5 * h + 1) % self.capacity
            if self.s[h] == "==TOMBSTONE==":
                break
        self.s[h] = key
        self.size += 1

    def remove(self, key):
        """
        :type key: int
        :rtype: void
        """
        h = self.myhash(key)
        while self.s[h] is not None:
            if self.s[h] == key:
                self.s[h] = "==TOMBSTONE=="
                self.size -= 1
                return
            h = (5 * h + 1) % self.capacity

    def contains(self, key):
        """
        Returns true if this set contains the specified element
        :type key: int
        :rtype: bool
        """
        h = self.myhash(key)
        while self.s[h] is not None:
            if self.s[h] == key:
                # return True
                return key
            h = (5 * h + 1) % self.capacity
        return False

    def displaySet(self):
        set = []
        for i in range(self.capacity):
            if (self.s[i] is not None and self.s[i] != "==TOMBSTONE=="):
                set.append(self.s[i])

        print("len(set): ", len(set))

        print("{", end="")
        for ele in sorted(set):
            print(str(ele), end=" ")
        print("}")


if __name__ == "__main__":
    myHashSet = MyHashSet()

    add = [30, 8, 79, 78, 81, 73, 99, 64, 77, 64, 57, 55, 27, 68, 70, 45, 54, 1, 84, 39, 19, 59, 38, 16, 51, 7, 10, 46,
           33, 89, 18, 89, 68, 25, 12, 48, 61, 93, 41, 57, 34, 29, 63, 65, 98, 73, 88, 24, 74, 38]

    rv = [9, 53, 5, 81, 84, 33, 24, 62, 55, 23, 10, 63, 98, 15, 36, 69, 30, 35, 26, 53, 81, 42, 98, 45, 43, 78, 19, 42,
          74, 77]

    contain = [87, 71, 85, 60, 72, 78, 1, 29, 83, 95, 57, 70, 70, 71, 43, 76, 47, 75, 77, 93, 79, 42, 16, 71, 48, 3, 61,
               71, 76, 49]

    for i in range(len(add)):
        myHashSet.add(add[i])

    myHashSet.displaySet()
    print(myHashSet.size)

    for i in range(len(rv)):
        myHashSet.remove(rv[i])

    myHashSet.displaySet()
    print(myHashSet.size)

    # for i in range(len(contain)):
    #     if myHashSet.contains(contain[i]) != False:
    #         print(myHashSet.contains(contain[i]))

    # myHashSet.displayHash()

    # print(myHashSet.size)
    #
    # myHashSet.displayHash()

    # for i in range(100000):
    #     myHashSet = MyHashSet()
    #     for j in range(8):
    #         data = np.random.randint(0, 100000)
    #         myHashSet.add(data)
    #     myHashSet.displayHash()
