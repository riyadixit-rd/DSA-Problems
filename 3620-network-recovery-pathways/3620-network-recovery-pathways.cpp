class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        int n = online.size();

        vector<vector<pair<int,int>>> g(n);
        vector<int> indeg(n);

        int mx = 0;

        for(auto &e:edges){
            g[e[0]].push_back({e[1],e[2]});
            indeg[e[1]]++;
            mx=max(mx,e[2]);
        }

        queue<int> q;
        vector<int> topo;

        for(int i=0;i<n;i++)
            if(indeg[i]==0)
                q.push(i);

        while(!q.empty()){
            int u=q.front();
            q.pop();
            topo.push_back(u);

            for(auto &x:g[u]){
                if(--indeg[x.first]==0)
                    q.push(x.first);
            }
        }

        auto check=[&](int lim){

            const long long INF=4e18;

            vector<long long> dist(n,INF);

            dist[0]=0;

            for(int u:topo){

                if(dist[u]==INF) continue;

                if(u!=0 && u!=n-1 && !online[u]) continue;

                for(auto &x:g[u]){

                    int v=x.first;
                    int w=x.second;

                    if(w<lim) continue;

                    if(v!=n-1 && !online[v]) continue;

                    dist[v]=min(dist[v],dist[u]+w);
                }
            }

            return dist[n-1]<=k;
        };

        int l=0,r=mx,ans=-1;

        while(l<=r){

            int mid=l+(r-l)/2;

            if(check(mid)){
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }

        return ans;
    }
};