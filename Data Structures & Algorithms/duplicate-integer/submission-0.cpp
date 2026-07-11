class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>x;
        for(int i=0;i<nums.size();i++){
            x[nums[i]]++;
        }
        for(auto i:x){
            if(i.second>1)return true;
        }
        return false;
    }
};