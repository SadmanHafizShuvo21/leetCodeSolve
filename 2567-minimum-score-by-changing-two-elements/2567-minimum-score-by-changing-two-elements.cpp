class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        
        return std::min({nums[n - 3] - nums[0], nums[n - 2] - nums[1], nums[n - 1] - nums[2]});
    }
};