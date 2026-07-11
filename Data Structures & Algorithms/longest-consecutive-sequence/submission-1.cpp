class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==0)return 0;
        int x=1;
        int cnt=1;
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1])continue;
            if((nums[i+1]-nums[i])==1)cnt++;
            else cnt=1;
            x=max(x,cnt);
        }
        return x;
    }
};
