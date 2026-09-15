class Solution {
public:
    int solve(int n,int start,vector<int>&dp,vector<int>&nums){
        if(n<start)return 0;
        if(n==start)return nums[n];
        if(dp[n]!=-1)return dp[n];
        int pick=nums[n]+solve(n-2,start,dp,nums);
        int notpick=0+solve(n-1,start,dp,nums);
        return dp[n]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>dp(n,-1);
        int x1= solve(n-2,0,dp,nums);
        vector<int>dp2(n,-1);
        int x2=solve(n-1,1,dp2,nums);
        return max(x1,x2);
    }
};