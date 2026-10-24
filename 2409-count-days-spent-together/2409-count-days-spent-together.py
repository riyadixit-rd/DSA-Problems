class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        start = max(arriveAlice, arriveBob)
        end = min(leaveAlice, leaveBob)
        return max(0, (lambda d: sum([31,28,31,30,31,30,31,31,30,31,30,31][:int(d[:2])-1]) + int(d[3:]))(end) - (lambda d: sum([31,28,31,30,31,30,31,31,30,31,30,31][:int(d[:2])-1]) + int(d[3:]))(start) + 1)