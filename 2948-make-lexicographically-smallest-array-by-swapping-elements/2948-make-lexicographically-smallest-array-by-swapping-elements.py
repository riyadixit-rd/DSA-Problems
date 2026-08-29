class Solution:
    def lexicographicallySmallestArray(self, nums, limit):
        n = len(nums)

        # (value, original_index)
        arr = [(nums[i], i) for i in range(n)]

        # Sort by value
        arr.sort()

        start = 0

        while start < n:
            end = start

            # Find all values that belong to the same group
            while end + 1 < n and arr[end + 1][0] - arr[end][0] <= limit:
                end += 1

            # Get original indices of this group
            indices = [arr[i][1] for i in range(start, end + 1)]

            # Smallest values should go to smallest indices
            indices.sort()

            for j in range(len(indices)):
                nums[indices[j]] = arr[start + j][0]

            start = end + 1

        return nums