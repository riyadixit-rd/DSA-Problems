class Solution {
    public long minSumSquareDiff(int[] nums1, int[] nums2, int k1, int k2) {
        int n = nums1.length, max = 0;
        long k = (long) k1 + k2, ans = 0;
        int[] diff = new int[n];

        for (int i = 0; i < n; i++) {
            diff[i] = Math.abs(nums1[i] - nums2[i]);
            max = Math.max(max, diff[i]);
        }

        int[] count = new int[max + 1];
        for (int d : diff) count[d]++;

        for (int d = max; d > 0 && k > 0; d--) {
            long move = Math.min(k, (long) count[d]);
            count[d] -= move;
            count[d - 1] += move;
            k -= move;
        }

        for (int d = 1; d < count.length; d++)
            ans += (long) d * d * count[d];

        return ans;
    }
}