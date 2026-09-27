class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long ,vector<int>>,vector<pair<long long,vector<int>>>,greater<>>pq;
        for(auto &i:points){
            int a=i[0],b=i[1];
            long long ans=(1LL*(a*a)+1LL*(b*b));//comaprision of a2+b2 is safe as root(a2+b2) as sqrt can cause floating point precision error
            pq.push({ans,{a,b}});
        }
        vector<vector<int>>res;
        while(k--){
            auto x=pq.top().second;
            res.push_back(x);
            pq.pop();
        }
        return res;
    }
};