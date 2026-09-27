class Solution {
public:
    void f(int idx,int target,vector<int>& candidates,vector<int>& x,vector<vector<int>>& ans){
        if(target==0 ){
            ans.push_back(x);
            return;
        }
        
        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1])continue;
            if(candidates[i]>target)break;
            x.push_back(candidates[i]);
            f(i+1,target-candidates[i],candidates,x,ans);
            x.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>x;
        vector<vector<int>>ans;
        f(0,target,candidates,x,ans);
        return ans;
    }
};