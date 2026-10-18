class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> a;

        for (int i = 0; i < n; i++) {
            int x = nums[i], sum = 0;
            while (x) {
                sum += x % 10;
                x /= 10;
            }
            a.push_back({sum, nums[i]});
        }

        sort(a.begin(), a.end());

        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++)
            pos[nums[i]] = i;

        vector<bool> vis(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || pos[a[i].second] == i)
                continue;

            int j = i, cycle = 0;
            while (!vis[j]) {
                vis[j] = true;
                j = pos[a[j].second];
                cycle++;
            }
            swaps += cycle - 1;
        }

        return swaps;
    }
};