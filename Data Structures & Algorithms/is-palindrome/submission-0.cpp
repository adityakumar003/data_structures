class Solution {
public:
    string cleanstring(string &s){
        string x="";
        for(auto i:s){
            if(isalnum(i)){
                x+=tolower(i);
            }
        }
        return x;
    }
    bool isPalindrome(string s) {
        string k=cleanstring(s);
        string x=k;
        reverse(x.begin(),x.end());
        return x==k;
    }
};
