class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> a = nums;
        sort(a.begin(), a.end());

        for (int k = 1; k <= n; k++) {
            if (n % k) continue;

            bool ok = true;
            for (int i = 0; i < n && ok; i += k) {
                vector<int> b(nums.begin() + i, nums.begin() + i + k);
                vector<int> c(a.begin() + i, a.begin() + i + k);

                bool found = false;
                for (int r = 0; r < k; r++) {
                    rotate(b.begin(), b.begin() + 1, b.end());
                    if (b == c) {
                        found = true;
                        break;
                    }
                }
                if (!found) ok = false;
            }

            if (ok) ans += k;
        }
        return ans;
    }
};