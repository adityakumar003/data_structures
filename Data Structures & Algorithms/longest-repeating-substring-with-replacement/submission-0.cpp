class Solution {
public:
    int characterReplacement(string s, int k) {
        int res=0;
        for(int i=0;i<s.length();i++){
            unordered_map<char,int>x;
            int m=0;
            for(int j=i;j<s.length();j++){
                x[s[j]]++;
                m=max(m,x[s[j]]);
                if((j-i+1)-m<=k){
                    res=max(res,j-i+1);
                }
            }
        }
        return res;
    }
};
