class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        // {stops, node, cost}
        queue<tuple<int,int,int>> q;
        q.push({0, src, 0});
        while(!q.empty()) {
            auto [stops, node, cost] = q.front();
            q.pop();
            if(stops > k) continue;
            for(auto &it : adj[node]) {
                int nextNode = it.first;
                int price = it.second;
                if(cost + price < dist[nextNode] && stops <= k) {
                    dist[nextNode] = cost + price;
                    q.push({stops + 1, nextNode, cost + price});
                }
            }
        }
        if(dist[dst] == 1e9)
            return -1;
        return dist[dst];
    }
};