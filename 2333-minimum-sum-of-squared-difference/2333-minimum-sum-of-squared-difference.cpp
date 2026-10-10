class Solution {
public:
    using ll = long long;
    const ll inf = 1e18;

    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        ll n = nums1.size(), mx = -inf;
        std::vector<ll> cnt(100001, 0);
        for (int i = 0; i < n; i++) {
            ll x = std::abs(nums1[i] - nums2[i]);
            cnt[x]++;

            mx = std::max(mx, x);
        }

        ll k = (ll)k1 + k2;
        for (int i = mx; i > 0 && k > 0; i--) {
            ll take = std::min(k, cnt[i]);

            cnt[i] -= take;
            cnt[i - 1] += take;
            k -= take;
        }

        ll ans = 0;
        for (int i = 1; i <= mx; i++) {
            ans += 1LL * i * i * cnt[i];
        }

        return ans;
    }
};