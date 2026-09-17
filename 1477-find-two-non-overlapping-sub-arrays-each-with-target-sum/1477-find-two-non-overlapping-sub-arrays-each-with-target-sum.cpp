class Solution {
public:
    using ll = long long;
    const ll inf = 1e9 + 7;

    int minSumOfLengths(vector<int>& arr, int target) {
        ll n = arr.size(), j = 0, sum = 0, best = inf, ans = inf;
        std::vector<ll> dp(n, inf);
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            while (sum > target) {
                sum -= arr[j++];
            }

            if (i > 0) {
                dp[i] = dp[i - 1];
            }

            if (sum == target) {
                ll len = i - j + 1;
                if (j > 0 && dp[j - 1] != inf) {
                    ans = std::min(ans, dp[j - 1] + len);
                }

                dp[i] = std::min(dp[i], len);
            }
        }

        return ans == inf ? -1 : ans;
    }
};