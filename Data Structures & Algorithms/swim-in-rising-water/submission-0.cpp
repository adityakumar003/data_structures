class Solution {
public:
    bool bfs(vector<vector<int>>& grid,int mid){
        int n= grid.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        queue<pair<int,int>>q;
        vis[0][0]=1;
        q.push({0,0});
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(x==n-1&&y==n-1)return true;
            for(int i=0;i<4;i++){
                int r=drow[i]+x;
                int c=dcol[i]+y;
                if(r>=0&&r<n&&c>=0&&c<n&&!vis[r][c]&&grid[r][c]<=mid){
                    q.push({r,c});
                    vis[r][c]=1;
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int l=grid[0][0];
        int h=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                h=max(h,grid[i][j]);
            }
        }
        int ans=h;
        while(l<h){
            int mid=l+(h-l)/2;
            if(bfs(grid,mid)){
                ans=min(ans,mid);
                h=mid;
            }
            else l=mid+1;
        }
        return l;
    }
};