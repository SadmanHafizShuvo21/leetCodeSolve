class Solution {
public:
    using ll = long long;
    const ll mod = 1e9 + 7;

    ll pw(ll a, ll b) {
        ll ans = 1;

        while (b) {
            if (b & 1) ans = ans * a % mod;
            a = a * a % mod;
            b >>= 1;
        }

        return ans;
    }

    int numberOfSets(int n, int k) {
        ll m = n + k - 1;
        std::vector<ll> fact(m + 1), inv(m + 1);
        fact[0] = 1;
        for (int i = 1; i <= m; i++) {
            fact[i] = fact[i - 1] * i % mod;
        }

        inv[m] = pw(fact[m], mod - 2);
        for (int i = m; i >= 1; i--) {
            inv[i - 1] = inv[i] * i % mod;
        }

        return fact[m] * inv[2 * k] % mod * inv[m - 2 * k] % mod;
    }
};