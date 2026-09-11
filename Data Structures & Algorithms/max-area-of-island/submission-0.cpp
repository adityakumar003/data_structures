class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid,int &size){
        int n=grid.size(),m=grid[0].size();
        if(i<0||i>=n||j<0||j>=m||grid[i][j]!=1)return;
        grid[i][j]=0;
        size++;
        dfs(i+1,j,grid,size);
        dfs(i-1,j,grid,size);
        dfs(i,j+1,grid,size);
        dfs(i,j-1,grid,size);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int size=0;
                    dfs(i,j,grid,size);
                    cnt=max(cnt,size);
                }

            }
        }
        return cnt;
    }
};