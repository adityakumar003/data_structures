class Solution {
public:
    int f(int i, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (i == 0) {
            if (target == 0 && arr[0] == 0) return 2;
            if (target == 0 || arr[0] == target) return 1;
            return 0;
        }
        if (dp[i][target] != -1)
            return dp[i][target];
        int not_take = f(i - 1, target, arr, dp);
        int take = 0;
        if (arr[i] <= target)
            take = f(i - 1, target - arr[i], arr, dp);

        return dp[i][target] = (take + not_take) ;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int s=accumulate(nums.begin(),nums.end(),0);
        if (abs(target) > s) return 0;
        if ((s + target) % 2 != 0) return 0;
        int tar=(s+target)/2;
        vector<vector<int>>dp(n,vector<int>(tar+1,-1));
        return f(n-1,tar,nums,dp);
    }
};