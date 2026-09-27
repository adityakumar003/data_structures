class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int l=0,r=matrix[0].size()-1,top=0,bot=matrix.size()-1;
        vector<int>a;
        while(l<=r && top<=bot){
            for(int i=l;i<=r;i++)a.push_back(matrix[top][i]);
            top++;
            for(int i=top;i<=bot;i++)a.push_back(matrix[i][r]);
            r--;
            if(top<=bot){
                for(int i=r;i>=l;i--)a.push_back(matrix[bot][i]);
                bot--;
            }
            if(l<=r){
                for(int i=bot;i>=top;i--)a.push_back(matrix[i][l]);
                l++;
            }

        }
        return a;
    }
};