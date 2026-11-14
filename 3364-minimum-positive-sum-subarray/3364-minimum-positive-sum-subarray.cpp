class Solution {
public:
    using ll = long long;
    const ll inf = 1e18;
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        ll n = nums.size();
        std::vector<ll> pref(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + nums[i - 1];
        }

        ll ans = inf;
        for (int i = 0; i < n; i++) {
            for (int j = l; j <= r && i + j <= n; j++) {
                ll x = pref[i + j] - pref[i];
                
                if (x > 0) {
                    ans = std::min(ans, x);
                }
            }
        }

        return ans == inf ? -1 : ans;
    }
};