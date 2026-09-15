class Solution {
public:
    int solve(int n,int start,vector<int>&dp,vector<int>&nums){
        if(n<start)return 0;
        if(dp[n]!=-1)return dp[n];
        int pick=nums[n]+solve(n-2,start,dp,nums);
        int notpick=0+solve(n-1,start,dp,nums);
        return dp[n]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>dp(n,-1);
        return solve(n-1,0,dp,nums);
        
    }
};