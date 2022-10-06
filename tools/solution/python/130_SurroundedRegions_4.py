
    def DFS(self, board, row, col):
        from collections import deque
        queue = deque([(row, col)])
        while queue:
            # pop out the _tail_ element, rather than the head.
            (row, col) = queue.pop()
            if board[row][col] != 'O':
                continue
            # mark this cell as escaped
            board[row][col] = 'E'
            # check its neighbour cells
            if col < self.COLS-1: queue.append((row, col+1))
            if row < self.ROWS-1: queue.append((row+1, col))
            if col > 0: queue.append((row, col-1))
            if row > 0: queue.append((row-1, col))
