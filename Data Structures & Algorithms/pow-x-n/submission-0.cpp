class Solution {
public:
    double myPow(double x, int n) {
        // return pow(x,n);
        double ans=1.00;
        long long b=n;
        if(n==0)return 1;
        if(b<0){
            x=1/x;
            b=-b;
        }
        while(b>0){
            if(b%2==1){
                ans=ans*x;
                b=b-1;
            }
            x*=x;
            b/=2;
        }
        return ans;
    }
};
