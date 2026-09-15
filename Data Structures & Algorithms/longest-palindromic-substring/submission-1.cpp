class Solution {
public:
     string longestPalindrome(string s) {
        int n=s.length();
        if(s.length()==1)return s;
        auto check_from_center=[&](int l,int r){
            while(l>=0 && r<n && s[l]==s[r]){
                l--;
                r++;
            }
            return s.substr(l+1,r-l-1);
        };
        string t=s.substr(0,1);
        for(int i=0;i<n;i++){
            string odd=check_from_center(i,i);
            string even=check_from_center(i,i+1);
            if(t.length()<odd.length())t=odd;
            if(t.length()<even.length())t=even;
        }
        return t;
    }
};