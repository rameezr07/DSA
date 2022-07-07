class Solution {  
    
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int t[n][n];
        int mx = 1, start = 0;
        memset(t, 0, sizeof(t));
        for (int i = 0; i < n; ++i)
            t[i][i] = 1;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i+1]) {
                t[i][i+1] = 1;
                start = i;
                mx = 2;
            }
        }
        for (int k = 3; k <= n; ++k) {
            for (int i = 0; i <= n - k; ++i) {
                int j = i + k - 1;
                if (t[i+1][j-1] == 1 && s[i] == s[j]) {
                    t[i][j] = 1;
                    if (k > mx) {
                        start = i;
                        mx = k;
                    }
                }
            }
        }
        return s.substr(start, mx);
    }
};