class Solution {
public:
    bool dfs(int node,int parent,vector<vector<int>>& edges,vector<int>&vis){
        vis[node]=1;
        for(auto &i:edges[node]){
            if(!vis[i]){
                if(dfs(i,node,edges,vis))return true;
            }
            else if(i!=parent)return true;
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
        for(auto&i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        if(dfs(0,-1,adj,vis))return false;
         
        for(int i=0;i<n;i++){
            if(!vis[i])return false;
        }
        return true;
    }
};
