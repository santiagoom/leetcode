class MyHashSet {
    /**
     *  Open Addressing for handling Collisions
     *  index = (5 * index + 1) % this->capacity;
     */
public:
    int capacity;
    float load_factor;
    int size;
    int *table;

    /** Initialize your data structure here. */
    MyHashSet() {
        this->capacity = 1 << 3;
        this->load_factor = 0.75;
        this->size = 0;
        this->table = new int[capacity];

        for (int i = 0; i < this->capacity; i++)
            this->table[i] = -1;
    }

    void add(int key) {
        int index = this->myhash(key);
        while (this->table[index] != -1) {
            if (this->table[index] == key)
                return;
            if (this->table[index] == -2)
                break;
            index = (5 * index + 1) % this->capacity;
        }
        this->table[index] = key;
        this->size += 1;

        if (float(this->size) / this->capacity >= this->load_factor)
            rehash();
    }

    void remove(int key) {
        int index = this->myhash(key);
        while (this->table[index] != -1) {
            if (this->table[index] == key) {
                this->table[index] = -2;
                this->size -= 1;
                return;
            }
            index = (5 * index + 1) % this->capacity;
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int index = this->myhash(key);
        while (this->table[index] != -1) {
            if (this->table[index] == key)
                return true;
            index = (5 * index + 1) % this->capacity;
        }
        return false;
    }

    int myhash(int key) {
        return key % this->capacity;
    }

    void rehash() {
        this->capacity <<= 1;
        int *newTable = new int[this->capacity];
        for (int i = 0; i < this->capacity; i++)
            newTable[i] = -1;

        for (int i = 0; i < this->capacity >> 1; i++) {
            if ((this->table[i] != -1) && (this->table[i] != -2)) {
                int index = this->myhash(this->table[i]);
                while (newTable[index] != -1)
                    index = (5 * index + 1) % this->capacity;
                newTable[index] = this->table[i];
            }
        }
        this->table = newTable;
    }

    void displayHash() {
        for (int i = 0; i < this->capacity; i++) {
            cout << i << " --> " << this->table[i] << endl;
        }
    }
};

