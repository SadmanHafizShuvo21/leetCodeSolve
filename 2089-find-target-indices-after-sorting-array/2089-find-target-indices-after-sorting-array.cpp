class Solution {
public:
    using ll = long long;
    vector<int> targetIndices(vector<int>& nums, int tar) {
        std::sort(nums.begin(), nums.end());
        
        std::vector<int> a;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == tar) {
                a.push_back(i);
            }
        }

        return a;
    }
};