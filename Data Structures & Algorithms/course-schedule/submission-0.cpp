class Solution {
public:
    bool dfs(int v, vector<vector<int>> &adj, vector<int>& vis, vector<int>& pathvis){
        vis[v]=1;
        pathvis[v]=1;
        for(auto i:adj[v]){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis)==true)return true;
            }else if(pathvis[i])return true;
        }
        pathvis[v]=0;//backtracking
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto &it : prerequisites) {
            int course = it[0];
            int prereq = it[1];
            adj[prereq].push_back(course);
        }
        vector<int>vis(numCourses,0),pathvis(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis)==true)return false;
            }
        }
        return true;
    }
};