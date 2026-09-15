class Solution {
public:
    using ll = long long;
    int maxPalindromes(string s, int k) {
        ll n = s.size();
        std::vector<std::vector<bool>> pal(n, std::vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 1 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }

        std::vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];

            for (int j = 0; j + k <= i; j++) {
                if (pal[j][i - 1]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n];
    }
};