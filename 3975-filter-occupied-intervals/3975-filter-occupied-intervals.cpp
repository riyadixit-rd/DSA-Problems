class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {

        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        vector<vector<int>> merged;

        for (auto &it : occupiedIntervals) {
            if (merged.empty() || it[0] > merged.back()[1] + 1) {
                merged.push_back(it);
            } else {
                merged.back()[1] = max(merged.back()[1], it[1]);
            }
        }

        vector<vector<int>> ans;

        for (auto &it : merged) {
            int l = it[0], r = it[1];

            if (r < freeStart || l > freeEnd) {
                ans.push_back({l, r});
            } else {
                if (l < freeStart)
                    ans.push_back({l, freeStart - 1});

                if (r > freeEnd)
                    ans.push_back({freeEnd + 1, r});
            }
        }

        return ans;
    }
};