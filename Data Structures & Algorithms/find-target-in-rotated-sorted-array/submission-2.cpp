class Solution {
public:
    int search(vector<int>& nums, int target) {
         int n=nums.size();
        int l=0,r=n-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target)return mid;
            if(nums[l]<=nums[mid]){
                if(nums[l]<=target && nums[mid]>target){
                    r=mid;
                }else l=mid+1;
            }
            else{
                if(nums[mid]<target && target<=nums[r]){
                    l=mid+1;
                }else r=mid;
            }
        }
        if(nums[l] == target) return l;
        return -1;
    }
};
