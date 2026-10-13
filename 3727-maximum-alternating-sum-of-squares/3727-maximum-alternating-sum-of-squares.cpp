class Solution {
public:
    using ll = long long;

    ll cal(ll x) {
        return 1LL * x * x;
    }

    long long maxAlternatingSum(vector<int>& nums) {
        ll n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[i] = cal(nums[i]);
        }

        sort(nums.begin(), nums.end());

        ll ans = 0;
        for (int i = 0; i < n / 2; i++) {
            ans -= nums[i];
        }

        for (int i = n / 2; i < n; i++) {
            ans += nums[i];
        }

        return ans;
    }
};