class Solution {
public:
    using ll = long long;
    const ll mx = 2048;
    int uniqueXorTriplets(vector<int>& nums) {
        std::vector<std::vector<ll>> dp(4, std::vector<ll>(mx, 0));

        dp[0][0] = 1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < mx; j++) {
                if (!dp[i][j]) {
                    continue;
                }

                for (auto k : nums) {
                    dp[i + 1][j ^ k] = 1;
                }
            }
        }

        ll ans = 0;
        for (int i = 0; i < mx; i++) {
            ans += dp[3][i];
        }

        return ans;
    }
};