class Solution {
public:
    vector<string> ans;

    vector<string> mp = {
        "", "",
        "abc", "def",
        "ghi", "jkl",
        "mno", "pqrs",
        "tuv", "wxyz"
    };

    void solve(string &digits, int idx, string &curr) {
        if (idx == digits.size()) {
            ans.push_back(curr);
            return;
        }

        for (char ch : mp[digits[idx] - '0']) {
            curr.push_back(ch);
            solve(digits, idx + 1, curr);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        string curr;
        solve(digits, 0, curr);
        return ans;
    }
};