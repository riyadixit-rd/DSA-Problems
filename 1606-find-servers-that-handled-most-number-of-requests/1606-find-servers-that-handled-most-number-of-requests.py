from sortedcontainers import SortedList
import heapq

class Solution:
    def busiestServers(self, k: int, arrival: list[int], load: list[int]) -> list[int]:
        available = SortedList(range(k))
        busy = []
        count = [0] * k

        for i, (t, l) in enumerate(zip(arrival, load)):
            while busy and busy[0][0] <= t:
                _, s = heapq.heappop(busy)
                available.add(s)

            if not available:
                continue

            j = available.bisect_left(i % k)
            if j == len(available):
                j = 0

            s = available.pop(j)
            count[s] += 1
            heapq.heappush(busy, (t + l, s))

        mx = max(count)
        return [i for i, c in enumerate(count) if c == mx]