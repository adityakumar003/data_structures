class Solution {
public:
    int maxSubArray(vector<int>& nums) {
         int n=nums.size();
        int sum=0;
        int max1=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>max1)max1=sum;
            if(sum<0)sum=0;
            
        }
        return max1;
    }
};
