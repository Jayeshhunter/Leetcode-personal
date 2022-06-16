class Solution {
  public:
    string longestPalindrome(string s) {
        int n = s.length();
        bool dp[n][n];
        memset(dp, false, sizeof(dp));
        
        int start = 0;
        int maxLength = 1;

        for(int i = 0; i < n; i++) {
            dp[i][i] = true;
            if(s[i] == s[i+1]) {
                dp[i][i+1] = true;
                if(start == 0) {
                    start = i;
                    maxLength = 2;
                } 
            }
        }
        
        for(int k = 3; k <= n; k++) {
            for(int i = 0; i < n - k + 1; i++) {
                int j = i + k - 1;
                if(s[i] == s[j] && dp[i + 1][j - 1] == true) {
                    dp[i][j] = true;
                    if(k > maxLength) {
                        start = i;
                        maxLength = k;
                    }
                }
            }
        }
        
        string ans = "";
        for(int i = start; i < start + maxLength; i++)
            ans += s[i];
        
        return ans;
    }
};