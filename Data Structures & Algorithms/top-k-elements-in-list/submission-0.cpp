class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>x;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            x[nums[i]]++;
        }
        vector<pair<int,int>>y(x.begin(),x.end());
        sort(y.begin(),y.end(),[](auto a,auto b){
            return a.second>b.second;
        });
        vector<int>res;
        for(int i=0;i<k;i++){
            res.push_back(y[i].first);
        }
        return res;
    }
};
