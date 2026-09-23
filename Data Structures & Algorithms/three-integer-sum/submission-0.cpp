class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>>result;
       int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i >0 && nums[i]==nums[i-1])continue;
            int k=n-1,j=i+1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0)j++;
                else if(sum>0)k--;
                else{
                    vector<int>a={nums[i],nums[j],nums[k]};
                    result.push_back(a);
                    j++;
                    k--;
                    while(j<n && nums[j]==nums[j-1])j++;//to remove reddunt nos
                    while(k>j && nums[k]==nums[k+1])k--;
                }
            }
        }
        return result; 
    }
};
