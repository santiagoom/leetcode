# bug

self.s[h] maybe 0, 0 can exit as an element.

```python
while self.s[h] is not None:
    if self.s[h] == key:
        return
    h = (5 * h + 1) % self.capacity
    if self.s[h] == "==TOMBSTONE==":
        break
self.s[h] = key
self.size += 1
```



correct

```cpp
for (Node *head = dummyHead; head->next != NULL; head = head->next) {
    if (head->next->key == key) {
        head->next = head->next->next;
        this->size -= 1;
        break;
    }
}
nodes[index] = dummyHead->next;
```



```java
for (Node head = dummyHead; head.next != null; head = head.next) {
        if (head.next.key == key) {
            head.next = head.next.next;
//                return;
            this.size -= 1;
            break;
        }
    }
    nodes[index] = dummyHead.next;
```



wrong

```cpp
for (Node *head = dummyHead; head->next != NULL; head = head->next) {
    if (head->next->key == key) {
        head->next = head->next->next;
        break;
    }
}
this->size -= 1;
nodes[index] = dummyHead->next;
```



```java
for (Node head = dummyHead; head.next != null; head = head.next) {
        if (head.next.key == key) {
            head.next = head.next.next;
//                return;
            break;
        }
    }
		this.size -= 1;
    nodes[index] = dummyHead.next;
```

