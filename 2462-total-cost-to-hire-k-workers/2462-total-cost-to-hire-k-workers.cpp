class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue<int, vector<int>, greater<int>> left, right;

        int l = 0, r = n - 1;

        for (int i = 0; i < candidates && l <= r; i++)
            left.push(costs[l++]);

        for (int i = 0; i < candidates && l <= r; i++)
            right.push(costs[r--]);

        long long ans = 0;

        while (k--) {
            if (right.empty() || (!left.empty() && left.top() <= right.top())) {
                ans += left.top();
                left.pop();

                if (l <= r)
                    left.push(costs[l++]);
            }
            else {
                ans += right.top();
                right.pop();

                if (l <= r)
                    right.push(costs[r--]);
            }
        }

        return ans;
    }
};