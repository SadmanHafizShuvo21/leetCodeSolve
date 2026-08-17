class Solution {
public:
    int dp[501][501];
    int sum[501];

    int f(int l, int r) {
        if (dp[l][r] != -1)
            return dp[l][r];

        int ans = 0;

        for (int m = l; m < r; m++) {
            int lsum = sum[m + 1] - sum[l];
            int rsum = sum[r + 1] - sum[m + 1];

            if (lsum <= rsum)
                ans = max(ans, lsum + f(l, m));

            if (lsum >= rsum)
                ans = max(ans, rsum + f(m + 1, r));

            if (2 * min(lsum, rsum) <= ans)
                break;
        }

        return dp[l][r] = ans;
    }
    int stoneGameV(vector<int>& st) {
        int n = st.size();

        sum[0] = 0;
        for (int i = 0; i < n; i++)
            sum[i + 1] = sum[i] + st[i];

        memset(dp, -1, sizeof(dp));

        return f(0, n - 1);
    }
};
