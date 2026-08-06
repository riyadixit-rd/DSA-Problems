class Solution {
public:
    int ans = 0;

    void dfs(int node, vector<vector<pair<int,int>>>& adj, vector<int>& vis) {
        vis[node] = 1;

        for (auto &it : adj[node]) {
            int next = it.first;
            int needsReverse = it.second;

            if (!vis[next]) {
                ans += needsReverse;
                dfs(next, adj, vis);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);

        for (auto &e : connections) {
            adj[e[0]].push_back({e[1], 1}); // original direction
            adj[e[1]].push_back({e[0], 0}); // reverse direction
        }

        vector<int> vis(n, 0);
        dfs(0, adj, vis);

        return ans;
    }
};