class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto & i:times){
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<int>dist(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            int t=pq.top().first;
            int src=pq.top().second;
            pq.pop();
            for(auto&i:adj[src]){
                int dst=i.first;
                int newt=i.second;
                if(dist[dst]>t+newt){
                    dist[dst]=t+newt;
                    pq.push({t+newt,dst});
                }
            }
        }
        int ans=0;
        for(int i=1;i<n+1;i++){
            if(dist[i]==1e9)
                return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};