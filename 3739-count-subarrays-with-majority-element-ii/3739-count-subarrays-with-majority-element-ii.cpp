class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();

        vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
        }

        vector<int> all = pref;
        sort(all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());

        int m = all.size();

        vector<int> bit(m + 2, 0);

        auto update = [&](int idx) {
            while (idx <= m) {
                bit[idx]++;
                idx += idx & -idx;
            }
        };

        auto query = [&](int idx) {
            int res = 0;
            while (idx > 0) {
                res += bit[idx];
                idx -= idx & -idx;
            }
            return res;
        };

        long long ans = 0;

        for (int x : pref) {

            int pos = lower_bound(all.begin(), all.end(), x) - all.begin() + 1;

            ans += query(pos - 1);

            update(pos);
        }

        return ans;
    }
};