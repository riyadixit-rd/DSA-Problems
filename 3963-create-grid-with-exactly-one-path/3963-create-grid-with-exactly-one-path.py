class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        g = [['#'] * n for _ in range(m)]
        for i in range(m):
            g[i][0] = '.'
        for j in range(n):
            g[m-1][j] = '.'
        return [''.join(r) for r in g]