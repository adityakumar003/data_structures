class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>x;
        int n=strs.size();
        for(auto i:strs){
            string y=i;
            sort(y.begin(),y.end());
            x[y].push_back(i);
        }
        vector<vector<string>>res;
        for(auto &i:x){
            res.push_back(i.second);
        }
        return res;
    }
};
