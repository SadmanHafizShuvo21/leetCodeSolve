class Solution {
public:
    using ll = long long;
    const ll inf = 1e18;

    int climbStairs(int n, vector<int>& costs) {
        std::vector<ll> dp(n + 1, inf);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3; j++) {
                if (i >= j) {
                    dp[i] = std::min(dp[i], dp[i - j] + costs[i - 1] + j * j);
                }
            }
        }

        return dp[n];
    }
};