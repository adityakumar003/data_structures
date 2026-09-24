class Solution {
public:
    bool dfs(int v, vector<vector<int>>&adj, vector<int>& vis, vector<int>& pathvis,vector<int>&res){
        vis[v]=1;
        pathvis[v]=1;
        for(auto i:adj[v]){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis,res))return true;
            }else if(pathvis[i])return true;
        }
        pathvis[v]=0;//backtracking
        res.push_back(v);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>res;
        vector<vector<int>>adj(numCourses);
        for(auto &i:prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        vector<int>vis(numCourses,0),pathvis(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis,res))return {};
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};