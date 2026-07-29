class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> mp;

        for (auto &row : grid)
            mp[row]++;

        int ans = 0, n = grid.size();

        for (int j = 0; j < n; j++) {
            vector<int> col;
            for (int i = 0; i < n; i++)
                col.push_back(grid[i][j]);
            ans += mp[col];
        }

        return ans;
    }
};