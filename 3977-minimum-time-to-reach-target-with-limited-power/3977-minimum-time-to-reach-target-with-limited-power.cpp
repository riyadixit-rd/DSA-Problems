class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges,
                                      int power, vector<int>& cost,
                                      int source, int target) {

        if (source == target)
            return {0, power};

        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges)
            adj[e[0]].push_back({e[1], e[2]});

        const long long INF = 4e18;

        vector<vector<long long>> dist(n, vector<long long>(power + 1, INF));

        priority_queue<
            tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>
        > pq;

        dist[source][power] = 0;
        pq.push({0, source, power});

        while (!pq.empty()) {
            auto [t, u, p] = pq.top();
            pq.pop();

            if (t != dist[u][p])
                continue;

            if (p < cost[u])
                continue;

            int np = p - cost[u];

            for (auto &[v, w] : adj[u]) {
                long long nt = t + w;

                if (nt < dist[v][np]) {
                    dist[v][np] = nt;
                    pq.push({nt, v, np});
                }
            }
        }

        long long bestTime = INF;
        int bestPower = -1;

        for (int p = 0; p <= power; p++) {
            if (dist[target][p] < bestTime) {
                bestTime = dist[target][p];
                bestPower = p;
            } else if (dist[target][p] == bestTime) {
                bestPower = max(bestPower, p);
            }
        }

        if (bestTime == INF)
            return {-1, -1};

        return {bestTime, (long long)bestPower};
    }
};