class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        if(s.empty())return true;
        int n= s.length();
        for(char i:s){
            if(i=='('||i=='{'||i=='[')st.push(i);
            else{
                if(st.empty())return false;
                char t=st.top();
                if(t=='('&& i!=')'||t=='['&& i!=']'||t=='{'&& i!='}')return false;
                else st.pop();
            }
        }
        return st.empty();
    }
};
