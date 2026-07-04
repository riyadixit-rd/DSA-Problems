class Solution {
public:
    int ans = INT_MAX;

    void dfs(int node, vector<vector<pair<int,int>>>& graph, vector<bool>& vis) {

        vis[node] = true;

        for (auto &it : graph[node]) {

            int next = it.first;
            int dist = it.second;

            ans = min(ans, dist);

            if (!vis[next])
                dfs(next, graph, vis);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> graph(n + 1);

        for (auto &r : roads) {
            graph[r[0]].push_back({r[1], r[2]});
            graph[r[1]].push_back({r[0], r[2]});
        }

        vector<bool> vis(n + 1, false);

        dfs(1, graph, vis);

        return ans;
    }
};