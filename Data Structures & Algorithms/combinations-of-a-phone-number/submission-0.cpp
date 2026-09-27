class Solution {
public:
    string f1(char digit){
        switch(digit){
            case '2':
                return "abc";
            case '3':
                return "def";
            case '4':
                return "ghi";
            case '5':
                return "jkl";
            case '6':
                return "mno";
            case '7':
                return "pqrs";
            case '8':
                return "tuv";
            case '9':
                return "wxyz";
        }
        return "";
    }
    void f(int i,vector<string>& res,string & digits, string & x){
            if(i==digits.length()){
                res.push_back(x);
                return;
            }
            string y=f1(digits[i]);
            for(int j=0;j<y.length();j++){
                x.push_back(y[j]);
                f(i+1,res,digits,x);
                x.pop_back();
            }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        string x="";
        vector<string>res;
        f(0,res,digits,x);
        return res;
        
    }
};