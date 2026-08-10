class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> a;

        for (int i = 0; i < nums1.size(); i++)
            a.push_back({nums2[i], nums1[i]});

        sort(a.rbegin(), a.rend());

        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0, ans = 0;

        for (auto [b, x] : a) {
            pq.push(x);
            sum += x;

            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            if (pq.size() == k)
                ans = max(ans, sum * b);
        }

        return ans;
    }
};