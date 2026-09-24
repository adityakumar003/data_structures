class Solution {
public:
    int drow[4]={-1,0,0,1},dcol[4]={0,-1,1,0};
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>& heights){
        int m=heights.size(),n=heights[0].size();
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int r=drow[i]+row;
            int c=dcol[i]+col;
            if(r<m&&r>=0&&c<n&&c>=0&&!vis[r][c]){
                if(heights[r][c]>=heights[row][col]){
                    dfs(r,c,vis,heights);
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));

        // Pacific: top row
        for(int j=0; j<n; j++) {
            dfs(0, j,pacific,heights);
        }

        // Pacific: left column
        for(int i=0; i<m; i++) {
            dfs(i, 0, pacific,heights);
        }

        // Atlantic: bottom row
        for(int j=0; j<n; j++) {
            dfs(m-1, j,atlantic,heights);
        }

        // Atlantic: right column
        for(int i=0; i<m; i++) {
            dfs(i, n-1,atlantic,heights);
        }

        vector<vector<int>> result;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {

                if(pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};


/// start


