
class Solution {
public:
    using ll = long long;
    const ll mod = 1e9 + 7;

    int maxSum(vector<int>& nums, int k) {
        std::vector<ll> cnt(31, 0);

        for (ll x : nums) {
            for (int b = 0; b < 31; b++) {
                if (x & (1LL << b)) {
                    cnt[b]++;
                }
            }
        }

        ll ans = 0;

        for (int i = 0; i < k; i++) {
            ll x = 0;

            for (int b = 30; b >= 0; b--) {
                if (cnt[b] > 0) {
                    x |= (1LL << b);
                    cnt[b]--;
                }
            }

            ans = (ans + x * x % mod) % mod;
        }

        return ans;
    }
};
