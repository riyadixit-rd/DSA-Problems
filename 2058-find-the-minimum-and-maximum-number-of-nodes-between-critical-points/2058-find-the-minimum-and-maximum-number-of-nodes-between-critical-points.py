class Solution:
    def nodesBetweenCriticalPoints(self, head):
        prev = head
        curr = head.next

        first = -1
        last = -1
        minDist = float('inf')

        pos = 1

        while curr.next:
            nxt = curr.next

            # Check if current node is a critical point
            if (curr.val > prev.val and curr.val > nxt.val) or \
               (curr.val < prev.val and curr.val < nxt.val):

                if first == -1:
                    # First critical point
                    first = pos
                else:
                    # Distance from previous critical point
                    minDist = min(minDist, pos - last)

                last = pos

            prev = curr
            curr = nxt
            pos += 1

        # Fewer than 2 critical points
        if first == -1 or first == last:
            return [-1, -1]

        maxDist = last - first

        return [minDist, maxDist]