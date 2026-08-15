class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr = 0;

        for (int x : nums) {
            xr ^= x;
        }

        // If XOR of the whole array is non-zero,
        // we can take the entire array.
        if (xr != 0) {
            return nums.size();
        }

        // Whole array XOR is 0.
        // Remove one non-zero element -> XOR becomes non-zero.
        for (int x : nums) {
            if (x != 0) {
                return nums.size() - 1;
            }
        }

        // All elements are zero.
        return 0;
    }
};