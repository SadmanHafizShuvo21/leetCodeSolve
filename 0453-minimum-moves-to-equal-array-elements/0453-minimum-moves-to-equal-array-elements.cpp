class Solution {
public:
    using ll = long long;
    int minMoves(vector<int>& nums) {
        ll mn = *std::min_element(nums.begin(), nums.end());

        ll ans = 0;
        for (auto x : nums) {
            ans += (x - mn);
        }

        return ans;
    }
};