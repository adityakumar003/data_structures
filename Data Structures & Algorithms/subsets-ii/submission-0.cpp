class Solution {
public:
    void f(int idx,vector<int>&nums,vector<int>& x,vector<vector<int>>& ans){
        
        ans.push_back(x);
        
        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1])continue;
            x.push_back(nums[i]);
            f(i+1,nums,x,ans);
            x.pop_back();
            
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>x;
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        f(0,nums,x,ans);
        return ans;
    }
};