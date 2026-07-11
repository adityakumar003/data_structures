class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>x;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int diff=target-nums[i];
            if(x.count(diff))return {x[diff],i};
            x[nums[i]]=i;
        }
        return {};
    }
};
