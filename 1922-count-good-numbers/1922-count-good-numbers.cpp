class Solution {
public:
    using ll = long long;
    const ll mod = 1e9 + 7;

    ll modpow(ll a, ll b) {
        ll ans = 1;

        while (b > 0) {
            if (b & 1) {
                ans = (ans * a) % mod;
            }

            a = (a * a) % mod;
            b >>= 1;
        }

        return ans;
    }
    int countGoodNumbers(long long n) {
        ll e = (n + 1) / 2;
        ll o = n / 2;

        ll ans = modpow(5, e) * modpow(4, o) % mod;

        return ans;
    }
};