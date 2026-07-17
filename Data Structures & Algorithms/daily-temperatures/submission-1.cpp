class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>res(n,n),x;
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&& temperatures[st.top()]<temperatures[i]){
                res[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        for(int i=0;i<n;i++){
            if (res[i] == n)
                x.push_back(0);
            else
                x.push_back(res[i] - i);
        }
        return x;
    }
};
