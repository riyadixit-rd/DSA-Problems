class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void dfs(int start, int k, int target) {
        if (k == 0 && target == 0) {
            ans.push_back(curr);
            return;
        }

        if (k == 0 || target < 0) return;

        for (int i = start; i <= 9; i++) {
            curr.push_back(i);
            dfs(i + 1, k - 1, target - i);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, k, n);
        return ans;
    }
};