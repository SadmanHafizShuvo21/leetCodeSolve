class Solution {
public:
    using ll = long long;
    const ll inf = 1e9 + 7;

    int sortPermutation(vector<int>& nums) {
        ll n = nums.size();

        ll ans = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                ans &= nums[i];
            }
        }

        return std::max(ans, 0LL);
    }
};