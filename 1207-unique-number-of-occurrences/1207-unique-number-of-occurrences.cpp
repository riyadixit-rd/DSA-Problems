class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        unordered_set<int> st;

        for (int x : arr)
            mp[x]++;

        for (auto &[_, cnt] : mp) {
            if (st.count(cnt))
                return false;
            st.insert(cnt);
        }

        return true;
    }
};