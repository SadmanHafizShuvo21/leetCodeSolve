class Solution {
public:
    const long long INF = INT_MAX;
    int numDistinct(string s, string t) {
        int m = t.size();
        
        vector<long long> dp(m + 1);
        dp[0] = 1;

        for (char c : s) {
            for (int j = m; j >= 1; --j) {
                if (c == t[j - 1]) {
                    dp[j] = min(INF, dp[j] + dp[j - 1]);
                }
            }
        }

        return dp[m];
    }
};