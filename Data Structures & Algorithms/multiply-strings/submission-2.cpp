class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int n = num1.size(), m = num2.size();
        vector<int> ans(n + m, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int x = (num1[i] - '0') * (num2[j] - '0');
                int sum = ans[i + j + 1] + x;
                ans[i + j + 1] = sum % 10;
                ans[i + j] += sum / 10;
            }
        }
        string s = "";
        for (int x : ans) {
            if (s.empty() && x == 0) continue;
            s += x + '0';
        }
        return s;
    }
};