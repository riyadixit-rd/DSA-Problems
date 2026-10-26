from typing import List

class Solution:
    def countIslands(self, grid: List[List[int]], k: int) -> int:
        m, n, ans = len(grid), len(grid[0]), 0

        for i in range(m):
            for j in range(n):
                if grid[i][j] > 0:
                    stack, s = [(i, j)], 0
                    s += grid[i][j]
                    grid[i][j] = 0

                    while stack:
                        x, y = stack.pop()
                        for a, b in ((x+1,y),(x-1,y),(x,y+1),(x,y-1)):
                            if 0 <= a < m and 0 <= b < n and grid[a][b] > 0:
                                s += grid[a][b]
                                grid[a][b] = 0
                                stack.append((a, b))

                    ans += s % k == 0
        return ans