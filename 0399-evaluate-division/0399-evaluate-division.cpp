class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;

    double dfs(string src, string dst, unordered_set<string>& vis, double val) {
        if (src == dst) return val;

        vis.insert(src);

        for (auto &it : graph[src]) {
            if (!vis.count(it.first)) {
                double ans = dfs(it.first, dst, vis, val * it.second);
                if (ans != -1.0)
                    return ans;
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {

        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double v = values[i];

            graph[a].push_back({b, v});
            graph[b].push_back({a, 1.0 / v});
        }

        vector<double> ans;

        for (auto &q : queries) {
            string a = q[0];
            string b = q[1];

            if (!graph.count(a) || !graph.count(b)) {
                ans.push_back(-1.0);
                continue;
            }

            unordered_set<string> vis;
            ans.push_back(dfs(a, b, vis, 1.0));
        }

        return ans;
    }
};