class Solution {
public:
    using ll = long long;
    long long maxPairStrength(vector<int>& nums) {
        ll n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ll g = gcd(nums[i], nums[j]);
                ll cal = 1LL * nums[i] * nums[j] / (g * g);
                ans = max(ans, cal);
            }
        }

        return ans;
    }
};