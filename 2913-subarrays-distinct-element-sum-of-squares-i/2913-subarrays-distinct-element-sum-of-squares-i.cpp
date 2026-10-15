class Solution {
public:
    using ll = long long;

    ll cal (ll x) {
        return 1LL * x * x;
    }

    int sumCounts(vector<int>& nums) {
        ll n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            std::unordered_set<ll> s;
            for (int j = i; j < n; j++) {
                s.insert(nums[j]);

                ll x = s.size();
                ans += cal(x);
            }
        }

        return ans;
    }
};