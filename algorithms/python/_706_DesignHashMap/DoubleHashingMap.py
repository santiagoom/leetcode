import numpy as np


class MyHashMap:
    """
    Open Addressing for handling Collisions
    using Double Hashing to implement
    newIndex = (index1 + i1 * index2) % self.capacity
    """

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.capacity = 1 << 3
        self.load_factor = 0.75
        self.size = 0
        self.prime = 7
        self.nodes = [Node(-1, -1)] * self.capacity

    def put(self, key, value):
        """
        value will always be non-negative.
        """
        index1 = self.myhash1(key)
        head = self.nodes[index1]

        if head.key == key:
            head.value = value
            return

        if head.key != -1:
            index2 = self.myhash2(key)
            i = 1
            while True:
                new_index = (index1 + i * index2) % self.capacity
                print(new_index)
                if self.nodes[new_index] == key:
                    self.nodes[new_index].value = value
                    return
                if self.nodes[new_index].key == -1:
                    self.nodes[new_index] = Node(key, value)
                    break
                i += 1
        else:
            self.nodes[index1] = Node(key, value)

        self.size += 1

    def get(self, key):
        """
        Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
        """

    def remove(self, key):
        """
        Removes the mapping of the specified value key if this map contains a mapping for the key
        """

    def myhash1(self, key):
        return key % self.capacity

    def myhash2(self, key):
        return self.prime - key % self.prime

    def rehash(self):
        pass

    def displayMap(self):
        for i in range(self.capacity):
            print(str(i) + ": key: " + str(self.nodes[i].key) + " value: " + str(self.nodes[i].value))


class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None


if __name__ == "__main__":
    # Your MyHashMap object will be instantiated and called as such:
    obj = MyHashMap()

    for i in range(8):
        data = np.random.randint(0, 100000)
        obj.put(data, i + 1)

    obj.displayMap()
    # obj.put(key,value)
    # param_2 = obj.get(key)
    # obj.remove(key)
