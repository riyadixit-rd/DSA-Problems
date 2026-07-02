class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> best(m, vector<int>(n, -1));

        queue<tuple<int,int,int>> q;

        int startHealth = health - grid[0][0];

        if(startHealth <= 0)
            return false;

        q.push({0,0,startHealth});
        best[0][0] = startHealth;

        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};

        while(!q.empty()){

            auto [x,y,h]=q.front();
            q.pop();

            if(x==m-1 && y==n-1)
                return true;

            for(int k=0;k<4;k++){

                int nx=x+dx[k];
                int ny=y+dy[k];

                if(nx<0 || ny<0 || nx>=m || ny>=n)
                    continue;

                int nh = h - grid[nx][ny];

                if(nh<=0)
                    continue;

                if(nh>best[nx][ny]){
                    best[nx][ny]=nh;
                    q.push({nx,ny,nh});
                }
            }
        }

        return false;
    }
};