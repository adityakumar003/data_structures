class Solution {
public:
    class dsu{
        public:
            vector<int>parent,size;
            dsu(int n){
                size.resize(n+1,1);
                parent.resize(n+1,0);
                for(int i=0;i<=n;i++)parent[i]=i;
            }
            int findp(int node){
                if(node==parent[node])return node;
                return parent[node]=findp(parent[node]);
            }
            bool par(int u,int v){
                return(findp(u)==findp(v));
            }
            void unionbysize(int u,int v){
                int upu=findp(u);
                int upv=findp(v);
                if(upu==upv)return ;
                if(size[upu]<=size[upv]){
                    parent[upu]=upv;
                    size[upv]+=size[upu];
                }else{
                    parent[upv]=upu;
                    size[upu]+=size[upv];
                }
            }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        dsu  ds(n);
        vector<vector<int>>res;
        for(auto &i:edges){
            int u=i[0];
            int v=i[1];
            if(ds.findp(u)==ds.findp(v))res.push_back({u,v});
            else{
                ds.unionbysize(u,v);
            }
        }
        for(int i=n-1;i>=0;i--){
            if(edges[i]==res.back())return res.back();
        }
        return {};
    }
};