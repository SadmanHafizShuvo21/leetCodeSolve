class Solution {
public:
    using ll = long long;

    ll digitSquare(ll n) {
        ll sum = 0;
        while (n > 0) {
            ll rem = n % 10;
            sum += (rem * rem);
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {
        std::vector<ll> cnt(1000, 0);
        for (int j = 0; j < 1000; j++) {
            n = digitSquare(n);
        }
        return n == 1;
    }
};