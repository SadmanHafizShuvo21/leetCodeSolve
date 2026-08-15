class Solution {
public:
    using ll = long long;
    int longestSubsequence(vector<int>& nums) {
        ll n = nums.size();

        ll has = 0, xr = 0;
        for (auto x : nums) {
            xr ^= x;

            if (x != 0) {
                has = 1;
            }
        }

        if (xr != 0) {
            return n;
        }

        if (has) {
            return n - 1;
        }

        return 0;
    }
};