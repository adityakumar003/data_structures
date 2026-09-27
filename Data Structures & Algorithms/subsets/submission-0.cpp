class Solution {
public:
    void f(int idx,vector<int>&nums,vector<int>& x,vector<vector<int>>& ans){
        if(idx==nums.size()){
            ans.push_back(x);
            return;
        }
        x.push_back(nums[idx]);
        f(idx+1,nums,x,ans);
        x.pop_back();
        f(idx+1,nums,x,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>x;
        vector<vector<int>>ans;
        f(0,nums,x,ans);
        return ans;
    }
};
