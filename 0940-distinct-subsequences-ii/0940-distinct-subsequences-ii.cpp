class Solution {
public:
    using ll = long long;
    const ll mod = 1e9 + 7;
    int distinctSubseqII(string s) {
        ll n = s.size();
        std::vector<ll> cnt(26, -1);
        std::vector<ll> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            ll x = s[i - 1] - 'a';

            dp[i] = (2 * dp[i - 1]) % mod;
            if (cnt[x] != -1) {
                dp[i] = (dp[i] - dp[cnt[x]] + mod) % mod;
            }

            cnt[x] = i - 1;
        }

        return (dp[n] - 1 + mod) % mod;
    }
};