class Solution {
public:
    using ll = unsigned long long;
    int maxLength(vector<int>& nums) {
        ll ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ll l = 1, g = 0, p = 1;
            for (int j = i; j < nums.size(); j++) {
                g = std::gcd(g, nums[j]);
                l = std::lcm(l, (ll)nums[j]);
                p *= (ll)nums[j];

                if (p == g * l) {
                    ans = std::max(ans, (ll)(j - i + 1));
                }
            }
        }

        return ans;
    }
};