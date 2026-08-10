class Solution {
public:
    using ll = long long;
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; 1LL * j * j <= i; j++) {
                ll sq = j * j;
                
                if (!dp[i - sq]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};