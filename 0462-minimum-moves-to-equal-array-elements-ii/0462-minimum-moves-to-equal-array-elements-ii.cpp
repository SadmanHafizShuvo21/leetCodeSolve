class Solution {
public:
    using ll = long long;
    int minMoves2(vector<int>& nums) {
        ll n = (nums.size())/ 2;

        std::sort(nums.begin(), nums.end());
        
        ll ans = 0, x = nums[n];
        for (auto a : nums) {
            ans += std::abs(a - x);
        }

        return ans;
    }
};