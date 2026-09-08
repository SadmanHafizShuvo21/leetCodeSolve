class Solution {
public:
    using ll = long long;

    ll countDigit(ll n) {
        ll cnt = 0;
        while (n > 0) {
            cnt++;
            n /= 10;
        }
        return cnt;
    }

    int countCommas(int n) {
        if (n < 1000) {
            return 0;
        }
        return n - 999;
    }
};