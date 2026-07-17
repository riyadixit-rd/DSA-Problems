class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' ||
               c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int cnt = 0, ans = 0;

        // First window
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) cnt++;
        }

        ans = cnt;

        // Slide the window
        for (int i = k; i < s.size(); i++) {
            if (isVowel(s[i])) cnt++;
            if (isVowel(s[i - k])) cnt--;

            ans = max(ans, cnt);
        }

        return ans;
    }
};