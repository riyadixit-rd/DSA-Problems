class Solution:
    def uniformArray(self, nums1):
        mn_odd = float('inf')
        mn_even = float('inf')

        for x in nums1:
            if x % 2:
                mn_odd = min(mn_odd, x)
            else:
                mn_even = min(mn_even, x)

        if mn_odd == float('inf') or mn_even == float('inf'):
            return True

        return mn_odd < mn_even