class Solution {
public:
    using ll = long long;
    const ll inf = 1e18;

    int firstStableIndex(vector<int>& nums, int k) {
        ll n = nums.size();
        std::vector<int> pref(n), suf(n);

        pref[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pref[i] = std::max(pref[i - 1], nums[i]);
        }

        suf[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = std::min(suf[i + 1], nums[i]);
        }

        std::vector<ll> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = pref[i] - suf[i];
        }

        for (int i = 0; i < n; i++) {
            if (arr[i] <= k)
            return i;
        }
        return -1;
    }
};