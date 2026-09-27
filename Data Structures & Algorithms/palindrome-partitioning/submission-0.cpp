class Solution {
public:
    bool pal(string x){
        string y=x;
        reverse(y.begin(),y.end());
        if(x==y)return true;
        return false;
    }
    void f(int idx,string & s,vector<string>&s1,vector<vector<string>>&s2){
        if(idx==s.length()){
            s2.push_back(s1);
            return;
        }
        for(int i=idx;i<s.length();i++){
            if(pal(s.substr(idx,i-idx+1))){
                s1.push_back(s.substr(idx,i-idx+1));
                f(i+1,s,s1,s2);
                s1.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>s1;
        vector<vector<string>>s2;
        f(0,s,s1,s2);
        return s2;
    }
};