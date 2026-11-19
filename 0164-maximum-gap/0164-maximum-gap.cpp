class Solution {
public:
    using ll = long long;
    const ll inf = 1e18;

    int maximumGap(vector<int>& nums) {
        ll n = nums.size();

        if (n < 2) {
            return 0;
        }

        std::sort(nums.begin(), nums.end());
        
        ll ans = -inf;
        for (int i = 0; i < n - 1; i++) {
            ans = std::max(ans, (ll)(nums[i + 1] - nums[i]));
        }

        return ans;
    }
};