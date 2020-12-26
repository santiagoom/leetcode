class Node {
public:
    int key;
    int value;
    Node *next;

    Node(int key, int value, Node *next) {
        this->key = key;
        this->value = value;
        this->next = next;
    }
};

class MyHashMap {
    /**
     * Separate Chaining for handling Collisions
     */
public:
    int capacity;
    float load_factor;
    int size;
    Node **nodes;

    /** Initialize your data structure here. */
    MyHashMap() {
        this->capacity = 1 << 3;
        this->load_factor = 0.75;
        this->size = 0;
        this->nodes = new Node *[this->capacity];

        for (int i = 0; i < this->capacity; i++)
            nodes[i] = NULL;
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = this->myhash(key);
        Node *head = this->nodes[index];

        while (head != NULL) {
            if (head->key == key) {
                head->value = value;
                return;
            }
            head = head->next;
        }
        this->nodes[index] = new Node(key, value, this->nodes[index]);
        this->size += 1;

        if (float(this->size) / this->capacity >= this->load_factor)
            rehash();
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = this->myhash(key);
        Node *head = this->nodes[index];

        while (head != NULL) {
            if (head->key == key) {
                return head->value;
            }
            head = head->next;
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = this->myhash(key);
        Node *dummyHead = new Node(-1, -1, this->nodes[index]);

        for (Node *head = dummyHead; head->next != NULL; head = head->next) {
            if (head->next->key == key) {
                head->next = head->next->next;
                this->size -= 1;
                break;
            }
        }
        nodes[index] = dummyHead->next;
    }

    int myhash(int key) {
        return key % this->capacity;
    }

    void rehash() {
        this->capacity <<= 1;
        Node **tmp = this->nodes;
        this->nodes = new Node *[this->capacity];
        this->size = 0;
        for (int i = 0; i < this->capacity; i++)
            nodes[i] = NULL;

        for (int i = 0; i < this->capacity >> 1; i++) {
            Node *head = tmp[i];
            while (head != NULL) {
                this->put(head->key, head->value);
                head = head->next;
            }
        }
    }

    void displayMap() {
        for (int i = 0; i < this->capacity; i++) {
            Node *head = this->nodes[i];
            cout << i << endl;
            while (head != NULL) {
                cout << "  key: " << head->key << " value: " << head->value << endl;
                head = head->next;
            }
        }
    }
};
