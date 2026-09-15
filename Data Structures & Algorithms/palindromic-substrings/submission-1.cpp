class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            // Odd length palindromes
            int left = i;
            int right = i;

            while(left >= 0 && right < n && s[left] == s[right]) {
                cnt++;
                left--;
                right++;
            }

            // Even length palindromes
            left = i;
            right = i + 1;

            while(left >= 0 && right < n && s[left] == s[right]) {
                cnt++;
                left--;
                right++;
            }
        }

        return cnt;
    }
};