class Solution {
public:
    using ll = long long;
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.rbegin(), nums.rend());
        return std::max({nums[0] * nums[1] * nums[2], nums[0] * nums[1] * nums[n - 1], nums[0] * nums[n - 1] * nums[n - 2]});
    }
};