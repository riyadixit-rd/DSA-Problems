class Solution {
public:
    int product(int num) {
        int p = 1;
        while (num > 0) {
            p *= (num % 10);
            num /= 10;
        }
        return p;
    }

    int smallestNumber(int n, int t) {
        while (true) {
            if (product(n) % t == 0)
                return n;
            n++;
        }
    }
};