class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int drow[]={-1,0,0,1},dcol[]={0,-1,1,0};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int step=q.front().second;
            q.pop();
            grid[r][c]=step;
            for(int i=0;i<4;i++){
                int row=drow[i]+r;
                int col=dcol[i]+c;
                if(row>=0&&row<n&&col>=0&&col<m&&grid[row][col]==2147483647&&vis[row][col]==0){
                    q.push({{row,col},step+1});
                    vis[row][col]=1;
                }
            }
        }
    }
};
