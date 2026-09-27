class Solution {
public:
    int jump(vector<int>& nums) {
         int farthest = 0,cnt=0,end=0;
         if(nums.size()==1)return 0;
        for(int i = 0; i < nums.size(); i++) {
            farthest=max(farthest,i+nums[i]);
            if(i==end){
                end=farthest;
                cnt++;
            }
            if(end >= nums.size() - 1)
                return cnt;
        }

        return cnt;
    }
    
};