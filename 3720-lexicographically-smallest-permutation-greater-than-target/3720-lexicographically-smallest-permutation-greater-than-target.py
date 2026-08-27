class Solution:
    def lexGreaterPermutation(self, s, target):
        a = sorted(s)
        n = len(s)

        # Try to build the answer equal to target
        for i in range(n):
            if a[i] > target[i]:
                return ''.join(a)
            
            if a[i] < target[i]:
                break

        # Standard next permutation logic
        a = list(s)
        a.sort()

        # Find the largest index i such that a[i] < target[i]
        for i in range(n - 1, -1, -1):
            remaining = list(s)
            
            # Match target prefix before i
            possible = True
            for j in range(i):
                if target[j] in remaining:
                    remaining.remove(target[j])
                else:
                    possible = False
                    break
            
            if not possible:
                continue

            # Find smallest character > target[i]
            bigger = [c for c in remaining if c > target[i]]

            if bigger:
                c = min(bigger)
                remaining.remove(c)

                return target[:i] + c + ''.join(sorted(remaining))

        return ""