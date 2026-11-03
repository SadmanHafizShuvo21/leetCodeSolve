class Solution {
public:
    using ll = long long;

    long long minimumMaxValue(int n, int index, int value) {
        if (value == 1) {
            return -1;
        }

        ll p = value;
        for (ll i = 2; i * i <= value; i++) {
            if (value % i == 0) {
                p = i;
                break;
            }
        }

        if (index > 0) {
            ll x = value - p - 2LL * (index - 1);
            if (x <= 0) {
                return -1;
            }
        }

        ll r = n - index - 1;
        if (r == 0) {
            return value;
        }

        return value + p + 2LL * (r - 1);
    }
};