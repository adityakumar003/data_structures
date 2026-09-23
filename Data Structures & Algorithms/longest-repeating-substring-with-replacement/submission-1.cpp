class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l=0,r=0,mx=0,mfre=0;
        unordered_map<char,int>x;
        while(r<n){
            x[s[r]]++;
            mfre=max(mfre,x[s[r]]);
            while((r-l+1)-mfre>k){// total len - mfreq will give changable options if its is more than k window invalid
                x[s[l]]--;
                for(auto&i:x)mfre=max(mfre,i.second);
                l++;
            }
            mx=max(mx,r-l+1);
            r++;
        }
        return mx;
    }
};
