class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pref;

        long long mx = 0;

        for (int x : nums) {
            mx = max(mx, (long long)x);
            pref.push_back(gcd(mx, (long long)x));
        }

        sort(pref.begin(), pref.end());

        long long ans = 0;
        int i = 0;
        int j = n - 1;

        while (i < j) {
            ans += gcd(pref[i], pref[j]);
            i++;
            j--;
        }

        return ans;
    }
};