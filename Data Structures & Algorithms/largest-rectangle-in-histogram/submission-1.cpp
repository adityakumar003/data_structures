class Solution {
public:
    vector<int> nxtsmaller(vector<int>& heights){
        int n=heights.size();
        vector<int>nxtres(n,n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&& heights[st.top()]>heights[i]){
                nxtres[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        return nxtres;
    }
    vector<int> prevsmaller(vector<int>& heights){
        int n=heights.size();
        vector<int>prevres(n,-1);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&& heights[st.top()]>=heights[i]){
                prevres[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        return prevres;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>x=nxtsmaller(heights);
        vector<int>y=prevsmaller(heights);
        int maxi=0;
        for(int i=0;i<heights.size();i++){
            int w=x[i]-y[i]-1;
            maxi=max(maxi,heights[i]*w);
        }
        return maxi;
    }
};
