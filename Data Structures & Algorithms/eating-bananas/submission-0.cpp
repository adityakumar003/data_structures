class Solution {
public:
    bool f(int mid,vector<int>& piles, int h){
        int n=piles.size(),cnt=0;
        int i=0;
        for(int i:piles){
            cnt+=(i+mid-1)/mid;
        }
        if(cnt<=h)return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1,r=*max_element(piles.begin(),piles.end());
        while(l<r){
            int mid=l+(r-l)/2;
            if(!f(mid,piles,h)){
                l=mid+1;
            }else r=mid;
        }
        return l;
    }
};
