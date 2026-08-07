#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    struct DigitFactors {
        int f2, f3, f5, f7;
    };

    // Prime factors contributed by digits 0..9
    const DigitFactors df[10] = {
        {0, 0, 0, 0}, // 0
        {0, 0, 0, 0}, // 1
        {1, 0, 0, 0}, // 2
        {0, 1, 0, 0}, // 3
        {2, 0, 0, 0}, // 4
        {0, 0, 1, 0}, // 5
        {1, 1, 0, 0}, // 6
        {0, 0, 0, 1}, // 7
        {3, 0, 0, 0}, // 8
        {0, 2, 0, 0}  // 9
    };

    // Computes the MINIMUM number of digits needed to satisfy prime factors (a, b, c, d)
    int min_digits_needed(int a, int b, int c, int d) {
        a = max(0, a);
        b = max(0, b);
        c = max(0, c);
        d = max(0, d);
        
        int count = c + d + (a / 3) + (b / 2);
        int ra = a % 3;
        int rb = b % 2;
        
        if (ra == 0 && rb == 0) {
            count += 0;
        } else if (ra == 2 && rb == 1) {
            count += 2; // e.g. 2 twos + 1 three = '6' + '2' or '3' + '4'
        } else {
            count += 1;
        }
        return count;
    }

    // Greedily constructs the lexicographically smallest suffix of length rem_len
    string fill_suffix(int rem_len, int req2, int req3, int req5, int req7) {
        string res = "";
        res.reserve(rem_len);
        for (int pos = 0; pos < rem_len; pos++) {
            for (int d = 1; d <= 9; d++) {
                int n2 = req2 - df[d].f2;
                int n3 = req3 - df[d].f3;
                int n5 = req5 - df[d].f5;
                int n7 = req7 - df[d].f7;
                
                if (min_digits_needed(n2, n3, n5, n7) <= rem_len - 1 - pos) {
                    res.push_back((char)('0' + d));
                    req2 = n2;
                    req3 = n3;
                    req5 = n5;
                    req7 = n7;
                    break;
                }
            }
        }
        return res;
    }

public:
    string smallestNumber(string num, long long t) {
        // Step 1: Factorize t into powers of 2, 3, 5, 7
        long long temp = t;
        int t2 = 0, t3 = 0, t5 = 0, t7 = 0;
        while (temp % 2 == 0) { temp /= 2; t2++; }
        while (temp % 3 == 0) { temp /= 3; t3++; }
        while (temp % 5 == 0) { temp /= 5; t5++; }
        while (temp % 7 == 0) { temp /= 7; t7++; }
        
        // If t has any prime factor other than 2, 3, 5, 7, it's impossible
        if (temp > 1) return "-1";

        int n = num.length();
        int first_zero_idx = n;
        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                first_zero_idx = i;
                break;
            }
        }

        // Prefix factor counts for zero-free prefix of num
        vector<int> pref2(n + 1, 0), pref3(n + 1, 0), pref5(n + 1, 0), pref7(n + 1, 0);
        for (int i = 0; i < first_zero_idx; i++) {
            int d = num[i] - '0';
            pref2[i + 1] = pref2[i] + df[d].f2;
            pref3[i + 1] = pref3[i] + df[d].f3;
            pref5[i + 1] = pref5[i] + df[d].f5;
            pref7[i + 1] = pref7[i] + df[d].f7;
        }

        // Step 2: Check if num itself is already valid
        if (first_zero_idx == n) {
            if (pref2[n] >= t2 && pref3[n] >= t3 && pref5[n] >= t5 && pref7[n] >= t7) {
                return num;
            }
        }

        // Step 3: Try to construct a number of length n matching a prefix of num
        int start_i = min(n - 1, first_zero_idx);
        for (int i = start_i; i >= 0; i--) {
            int p2 = pref2[i];
            int p3 = pref3[i];
            int p5 = pref5[i];
            int p7 = pref7[i];

            int start_d = (i == first_zero_idx) ? 1 : (num[i] - '0' + 1);
            for (int d = start_d; d <= 9; d++) {
                int rem2 = t2 - p2 - df[d].f2;
                int rem3 = t3 - p3 - df[d].f3;
                int rem5 = t5 - p5 - df[d].f5;
                int rem7 = t7 - p7 - df[d].f7;
                int rem_len = n - 1 - i;

                if (min_digits_needed(rem2, rem3, rem5, rem7) <= rem_len) {
                    string ans = num.substr(0, i);
                    ans.push_back((char)('0' + d));
                    ans += fill_suffix(rem_len, rem2, rem3, rem5, rem7);
                    return ans;
                }
            }
        }

        // Step 4: If no valid number of length n exists, construct smallest of length L > n
        int min_req_len = min_digits_needed(t2, t3, t5, t7);
        int L = max(n + 1, min_req_len);
        return fill_suffix(L, t2, t3, t5, t7);
    }
};