class Solution {
public:
    void f(int idx,int target,vector<int>& candidates,vector<int>& x,vector<vector<int>>& ans){
        if(idx==candidates.size()){
            if(target==0)ans.push_back(x);
            return;
        }
        if(candidates[idx]<=target){//pick
            x.push_back(candidates[idx]);
            f(idx,target-candidates[idx],candidates,x,ans);
            x.pop_back();
        }
        f(idx+1,target,candidates,x,ans);//not pick
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>x;
        vector<vector<int>>ans;
        f(0,target,candidates,x,ans);
        return ans;
    }
};
