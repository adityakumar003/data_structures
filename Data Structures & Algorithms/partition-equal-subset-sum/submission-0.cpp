class Solution {
public:
    bool f(int i,int target,vector<int>& nums,vector<vector<int>>&dp){
        if(target==0)return true;
        if(i==0)return (nums[i]==target);
        if(dp[i][target]!=-1)return dp[i][target];
        bool not_take=f(i-1,target,nums,dp);
        bool take=false;
        if(nums[i]<=target){
            take=f(i-1,target-nums[i],nums,dp);
        }
        return dp[i][target]=(take||not_take);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int s=accumulate(nums.begin(),nums.end(),0);
        if(s%2!=0)return false;
        int target=s/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return f(n-1,target,nums,dp);

    }
};