class Solution {
public:
    using ll = long long;
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        auto lcm = [](ll a, ll b) {
            return a / gcd(a, b) * b;
        };

        auto count = [&](ll x) {
            ll ans = 0;

            for (int mask = 1; mask < (1 << n); mask++) {
                ll l = 1, bits = 0;
                bool ok = true;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;

                        l = lcm(l, coins[i]);

                        if (l > x) {
                            ok = false;
                            break;
                        }
                    }
                }

                if (!ok) {
                    continue;
                }

                if (bits & 1){
                    ans += x / l;
                }
                else {
                    ans -= x / l;
                }
            }

            return ans;
        };

        ll lo = 1, hi = 1;
        while (count(hi) < k){
            hi *= 2;
        }

        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;
            if (count(mid) >= k) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};