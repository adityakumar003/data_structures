class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>res(n,0);
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=i+1;j<n;j++){
                if(temperatures[i]<temperatures[j]){
                    cnt=(j-i);
                    break;
                }
            }
            res[i]=cnt;
        }
        return res;
    }
};
