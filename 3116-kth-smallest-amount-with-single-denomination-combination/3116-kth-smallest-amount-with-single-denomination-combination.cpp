class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long lo = 1, hi = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            long long count = 0;

            int n = coins.size();

            for (int mask = 1; mask < (1 << n); mask++) {
                long long lcm = 1;
                int bits = 0;
                bool ok = true;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;

                        long long g = gcd(lcm, (long long)coins[i]);
                        lcm = lcm / g * coins[i];

                        if (lcm > mid) {
                            ok = false;
                            break;
                        }
                    }
                }

                if (ok) {
                    long long x = mid / lcm;
                    if (bits & 1) count += x;
                    else count -= x;
                }
            }

            if (count >= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};