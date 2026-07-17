class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>res;
        for(int i=0;i<=n-k;i++){
            int maxi=nums[i];
            for(int j=i;j<k+i;j++){
                maxi=max(maxi,nums[j]);
            }
            res.push_back(maxi);
        }
        return res;
    }
};
