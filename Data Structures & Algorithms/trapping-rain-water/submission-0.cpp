class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int res=0;
        for(int i=0;i<n;i++){
            int l=height[i];
            int r=height[i];
            for(int j=0;j<i;j++){
                l=max(l,height[j]);
            }
            for(int j=i+1;j<n;j++){
                r=max(r,height[j]);
            }
            res+=min(l,r)-height[i];
        }
        return res;
    }
};
