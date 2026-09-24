class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>, int>> q;  // {{row,col},time}
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Push all initially rotten oranges into the queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i,j}, 0});
                    vis[i][j] = 2; // mark rotten
                }
            }
        }

        int tm = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        // BFS
        while(!q.empty()) {
            int a = q.front().first.first;
            int b = q.front().first.second;
            int c = q.front().second;
            tm = max(tm, c);
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nrow = a + drow[i];
                int ncol = b + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                   && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0) {
                    q.push({{nrow,ncol}, c+1});
                    vis[nrow][ncol] = 2; // mark as rotten
                }
            }
        }

        // Check if any fresh orange is left
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && vis[i][j] != 2) {
                    return -1;
                }
            }
        }

        return tm;
    }
};
