class MyHashSet:

    def __init__(self):
        self.arr = [False] * 1000000

    def add(self, key):
        self.arr[key] = True

    def remove(self, key):
        self.arr[key] = False

    def contains(self, key):
        return self.arr[key]
