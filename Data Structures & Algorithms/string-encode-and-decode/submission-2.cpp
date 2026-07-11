class Solution {
public:

    string encode(vector<string>& strs) {
        string res="";
        for(auto &i:strs){
            res += to_string(i.length()) + "#" + i;
        }
        return res;
    }

    vector<string> decode(string res) {
        vector<string> rest;
        int n = res.length();
        int i = 0;
        while (i < n) {
            int j = i;
            while (res[j] != '#') j++;
            int len = stoi(res.substr(i, j - i));
            rest.push_back(res.substr(j + 1, len));
            i = j + 1 + len;
        }
        return rest;
    }
};
