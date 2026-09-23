class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mpro=0,j=0;
        for(int i=1;i<n;i++){
            int diff=prices[i]-prices[j];
            mpro=max(mpro,diff);
            if(diff<0)j=i;
        }
        return mpro;
    }
};
