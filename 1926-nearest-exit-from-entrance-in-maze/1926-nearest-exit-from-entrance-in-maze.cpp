class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();

        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';

        int steps = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c] = q.front();
                q.pop();

                if ((r == 0 || r == m - 1 || c == 0 || c == n - 1) &&
                    !(r == entrance[0] && c == entrance[1]))
                    return steps;

                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                        maze[nr][nc] == '.') {
                        maze[nr][nc] = '+';
                        q.push({nr, nc});
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};