class Solution {
public:
    using ll = long long;
    int minimumDeletions(vector<int>& nums) {
        ll n = nums.size();
        ll mn = min_element(nums.begin(), nums.end()) - nums.begin();
        ll mx = max_element(nums.begin(), nums.end()) - nums.begin();

        ll l = min(mn, mx), r = max(mn, mx);
        return min({r + 1, n - l, l + 1 + n - r});
    }
};