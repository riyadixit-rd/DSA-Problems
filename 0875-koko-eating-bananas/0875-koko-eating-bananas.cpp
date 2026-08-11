class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long l = 1, r = *max_element(piles.begin(), piles.end());

        while (l < r) {
            long long k = l + (r - l) / 2;
            long long hours = 0;

            for (int p : piles)
                hours += (p + k - 1) / k;

            if (hours <= h)
                r = k;
            else
                l = k + 1;
        }

        return l;
    }
};