class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>freq(26);
        int mfreq=0;
        int gsize=0;
        for(auto & i:tasks){
            freq[i]++;
            mfreq=max(mfreq,freq[i]);
        }
        for(auto& i:freq){
            if(i.second==mfreq)gsize++;
        }
        int res=(mfreq-1)*(n+1)+gsize;
        int size=tasks.size();
        return max(res,size);
    }
};
