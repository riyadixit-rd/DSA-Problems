class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;

        while (a || b || c) {
            int bitA = a & 1;
            int bitB = b & 1;
            int bitC = c & 1;

            if (bitC == 0) {
                ans += bitA + bitB;
            } else {
                if (bitA == 0 && bitB == 0)
                    ans++;
            }

            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return ans;
    }
};