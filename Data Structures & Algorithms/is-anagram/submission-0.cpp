class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;
        unordered_map<char,int>x;
        unordered_map<char,int>y;
        for(int i=0;i<s.length();i++){
            x[s[i]]++;
            y[t[i]]++;
        }
        return x==y;
    }
};
