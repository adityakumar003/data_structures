class Solution {
public:
    int f(int i,int amount,vector<int>& coins,vector<vector<int>>&dp){
        if(amount==0)return 0;
        if(i==0){
            if(amount%coins[0]==0)
                return amount/coins[0];
            return 1e9;//if target is modeulation of last value then 1 else 0;
        }
        if(dp[i][amount]!=-1)return dp[i][amount];
        int ntake=f(i-1,amount,coins,dp);
        int take=1e9;
        if(amount>=coins[i]){
            take=1+f(i,amount-coins[i],coins,dp);
        }
        return dp[i][amount]=min(take,ntake);
    }
    int coinChange(vector<int>& coins,int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=f(n-1,amount,coins,dp);
        if(ans>=1e9)return -1;
        return ans;
    }
};