class Solution {
public:
    using ll = long long;

    ll chk(ll n) {
        return 1LL * n * (n + 1) / 2;
    }

    int pivotInteger(int n) {
        ll x = std::sqrtl(chk(n));

        return x * x == chk(n) ? x : -1;
    }
};