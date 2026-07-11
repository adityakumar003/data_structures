class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mpro=0;
        int i=0,j=1;
        while(j<n){
            if(prices[i]<prices[j]){
                int profit=prices[j]-prices[i];
                mpro=max(mpro,profit);
                j++;
            }
            else{
                i=j;
                j+=1;
            }
        }
        return mpro;
    }
};
