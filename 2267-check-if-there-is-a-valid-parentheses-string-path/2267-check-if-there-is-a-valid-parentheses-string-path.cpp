class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if ((m + n - 1) % 2 || grid[0][0] == ')') {
            return false;
        }

        vector<bitset<201>> dp(n);
        dp[0][1] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                bitset<201> cur;
                if (i > 0) {
                    cur |= dp[j];
                }

                if (j > 0) {
                    cur |= dp[j - 1];
                }

                bitset<201> nxt;
                if (grid[i][j] == '(') {
                    for (int b = 0; b < 200; b++) {
                        if (cur[b]) {
                            nxt[b + 1] = 1;
                        }
                    }
                } 
                else {
                    for (int b = 1; b <= 200; b++) {
                        if (cur[b]) {
                            nxt[b - 1] = 1;
                        }
                    }
                }

                dp[j] = nxt;
            }
        }

        return dp[n - 1][0];
    }
};