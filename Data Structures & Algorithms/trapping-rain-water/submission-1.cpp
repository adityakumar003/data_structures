class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1,lmax=0,rmax=0,res=0;
        while(l<=r){
            lmax=max(lmax,height[l]);
            rmax=max(rmax,height[r]);
            if(lmax<=rmax){
                res+=lmax-height[l];
                l++;
            }else{
                res+=rmax-height[r];
                r--;
            }
        }
        return res;
    }
};
