class Solution {
public:
    int f(int n,vector<int>&dp,vector<int>&cost){
        if(n==0||n==1)return cost[n];
        if(dp[n]!=-1)return dp[n];
        int climb1=f(n-1,dp,cost)+cost[n];
        int climb2=f(n-2,dp,cost)+cost[n];
        return dp[n]=min(climb1,climb2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return min(f(n-1,dp,cost),f(n-2,dp,cost));
    }
};