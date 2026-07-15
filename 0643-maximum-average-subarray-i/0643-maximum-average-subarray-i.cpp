class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long sum = 0;

        // First window
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        long long maxSum = sum;

        // Slide the window
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i];
            sum -= nums[i - k];

            maxSum = max(maxSum, sum);
        }

        return (double)maxSum / k;
    }
};