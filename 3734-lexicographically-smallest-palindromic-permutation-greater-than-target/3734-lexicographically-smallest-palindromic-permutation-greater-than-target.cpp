class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int m = n / 2;

        // Count characters
        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Check if palindrome is possible
        int odd = 0;
        char middle = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) {
                odd++;
                middle = char('a' + i);
            }
        }

        if (odd > 1) {
            return "";
        }

        // Characters available in the left half
        vector<int> half(26);

        for (int i = 0; i < 26; i++) {
            half[i] = cnt[i] / 2;
        }

        // Build palindrome from left half
        auto build = [&](string left) {
            string right = left;
            reverse(right.begin(), right.end());

            if (n % 2 == 1) {
                return left + string(1, middle) + right;
            }

            return left + right;
        };

        // ----------------------------------------------------
        // First, try left half exactly equal to target's half
        // ----------------------------------------------------
        vector<int> remaining = half;
        bool possible = true;

        string left = "";

        for (int i = 0; i < m; i++) {
            int x = target[i] - 'a';

            if (remaining[x] == 0) {
                possible = false;
                break;
            }

            remaining[x]--;
            left += target[i];
        }

        if (possible) {
            string candidate = build(left);

            if (candidate > target) {
                return candidate;
            }
        }

        // ----------------------------------------------------
        // Find the smallest left half greater than target half
        // ----------------------------------------------------

        // Try changing position i, starting from the right.
        for (int i = m - 1; i >= 0; i--) {

            // Rebuild counts for target[0 ... i-1]
            remaining = half;
            bool prefixPossible = true;

            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                if (remaining[x] == 0) {
                    prefixPossible = false;
                    break;
                }

                remaining[x]--;
            }

            if (!prefixPossible) {
                continue;
            }

            int current = target[i] - 'a';

            // Choose the smallest character greater than target[i]
            for (int bigger = current + 1; bigger < 26; bigger++) {

                if (remaining[bigger] == 0) {
                    continue;
                }

                vector<int> temp = remaining;
                temp[bigger]--;

                string newLeft = target.substr(0, i);
                newLeft += char('a' + bigger);

                // Fill remaining positions with smallest characters
                for (int c = 0; c < 26; c++) {
                    while (temp[c] > 0) {
                        newLeft += char('a' + c);
                        temp[c]--;
                    }
                }

                string candidate = build(newLeft);

                if (candidate > target) {
                    return candidate;
                }
            }
        }

        return "";
    }
};