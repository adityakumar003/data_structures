class Solution {
public:
    bool isHappy(int n) {
        set<int>st;
        if(n==1)return true;
        while(n!=1){
            if(st.count(n))return false;
            st.insert(n);
            int sum=0;
            while(n){
                int d=n%10;
                sum+=d*d;
                n/=10;
            }
            n=sum;
        }
        return true;
    }
};
