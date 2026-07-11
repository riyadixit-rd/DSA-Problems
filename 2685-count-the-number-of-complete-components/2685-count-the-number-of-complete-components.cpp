class Solution {
public:
    vector<int> adj[55];
    vector<bool> vis;

    void dfs(int node, int& nodes, int& edges) {
        vis[node] = true;
        nodes++;
        edges += adj[node].size();

        for (int nei : adj[node]) {
            if (!vis[nei])
                dfs(nei, nodes, edges);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vis.assign(n, false);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int nodes = 0;
                int edgeCount = 0;

                dfs(i, nodes, edgeCount);

                edgeCount /= 2;

                if (edgeCount == nodes * (nodes - 1) / 2)
                    ans++;
            }
        }

        return ans;
    }
};