class Solution {
public:
    using ll = long long;
    const ll mod = 1e9 + 7;
    const ll inf = 1e9 + 7;

    int uniquePaths(vector<vector<int>>& grid) {
        ll m = grid.size(), n = grid[0].size();
        std::vector<std::vector<ll>> dp1(m, std::vector<ll>(n, 0));
        std::vector<std::vector<ll>> dp2(m, std::vector<ll>(n, 0));

        dp1[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == m - 1 && j == n - 1) {
                    return (dp1[i][j] + dp2[i][j]) % mod;
                }

                if (grid[i][j] == 0) {
                    long long ways = (dp1[i][j] + dp2[i][j]) % mod;

                    if (j + 1 < n) {
                        dp1[i][j + 1] = (dp1[i][j + 1] + ways) % mod;
                    }

                    if (i + 1 < m) {
                        dp2[i + 1][j] = (dp2[i + 1][j] + ways) % mod;
                    }
                }
                else {
                    if (i + 1 < m) {
                        dp2[i + 1][j] = (dp2[i + 1][j] + dp1[i][j]) % mod;
                    }

                    if (j + 1 < n) {
                        dp1[i][j + 1] = (dp1[i][j + 1] + dp2[i][j]) % mod;
                    }
                }
            }
        }

        return 0;
    }
};