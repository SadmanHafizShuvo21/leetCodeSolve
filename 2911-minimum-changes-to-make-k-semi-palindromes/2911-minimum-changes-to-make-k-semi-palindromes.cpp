
class Solution {
public:
    using ll = long long;
    const ll inf = 1e9;
    int minimumChanges(string s, int k) {
        int n = s.size();
        vector<vector<int>> cost(n, vector<int>(n, inf));
        for (int l = 0; l < n; l++) {
            for (int r = l + 1; r < n; r++) {
                int len = r - l + 1;

                for (int d = 1; d < len; d++) {
                    if (len % d != 0) {
                        continue;
                    }

                    int cnt = 0;

                    for (int i = 0; i < d; i++) {
                        int x = l + i;
                        int y = r - (d - 1 - i);

                        while (x < y) {
                            if (s[x] != s[y]) {
                                cnt++;
                            }

                            x += d;
                            y -= d;
                        }
                    }

                    cost[l][r] = min(cost[l][r], cnt);
                }
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, inf));
        dp[0][0] = 0;

        for (int j = 1; j <= k; j++) {
            for (int i = 2 * j; i <= n; i++) {
                for (int p = 2 * (j - 1); p < i; p++) {

                    if (dp[p][j - 1] == inf || cost[p][i - 1] == inf) {
                        continue;
                    }

                    dp[i][j] = min(
                        dp[i][j],
                        dp[p][j - 1] + cost[p][i - 1]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
