class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        if(n<t.size())return "";
        unordered_map<char,int>x;
        unordered_map<char,int>freq;
        for(auto &i:t){
            x[i]++;
            freq[i]=0;
        }
        int l=0,r=0,cnt=0,mini=INT_MAX,start=0;
        while(r<n){
            if(x.count(s[r])){
                freq[s[r]]++;
                if(freq[s[r]]==x[s[r]])cnt++;
            }
            while(cnt==x.size()){
                    if(r-l+1<mini){
                        mini=r-l+1;
                        start=l;
                    }
                    if(x.count(s[l])){
                        freq[s[l]]--;
                        if(freq[s[l]]<x[s[l]])cnt--;
                    }
                    l++;
            }
            r++;
        }
        if(mini==INT_MAX)return "";
        return s.substr(start,mini);
    }
};
