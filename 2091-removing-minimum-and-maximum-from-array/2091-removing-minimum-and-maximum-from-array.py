class Solution:
    def minimumDeletions(self, nums):
        n = len(nums)

        min_idx = nums.index(min(nums))
        max_idx = nums.index(max(nums))

        left = min(min_idx, max_idx)
        right = max(min_idx, max_idx)

        # Both from the left
        option1 = right + 1

        # Both from the right
        option2 = n - left

        # Minimum from left, maximum from right
        option3 = (left + 1) + (n - right)

        return min(option1, option2, option3)