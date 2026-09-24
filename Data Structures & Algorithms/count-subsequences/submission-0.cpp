class Solution {
public:
    const int MOD=1e9+7;
    int f(int i,int j,string &s, string &t,vector<vector<int>>&dp){
        if(j==0)return 1;
        if(i==0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        long long int cnt=f(i-1,j,s,t,dp);
        if(s[i-1]==t[j-1]){// cause easy to write the last letter of both string matched 
            cnt+=f(i-1,j-1,s,t,dp);
        }
        return dp[i][j]=(int)(cnt%MOD);
    }
    int numDistinct(string s, string t) {
        int n=s.length(),m=t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(n,m,s,t,dp);
    }
};
