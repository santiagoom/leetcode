```
However, it is a non-trivial algorithm, and no one expects you to come up with this algorithm in a 45 minutes coding session. But, please go ahead and understand it, I promise it will be a lot of fun.

Have a nice coding
```



```
解递归经验：
从递归退出条件往回推

递归的三层境界
1. 求阶层
2. 分治算法
3. 回溯算法
```



## Hashing

哈希函数避免进入死循环。

注意下列语句的差别

```python
self.nodes = [Node(-1, -1)] * self.capacity  # 同一个节点
self.nodes = [Node(-1, -1) for _ in range(self.capacity)]
```

