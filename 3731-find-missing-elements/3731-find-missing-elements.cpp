class Solution {
public:
    using ll = long long;
    vector<int> findMissingElements(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        ll l = nums[0], r = nums.back();
        std::unordered_set<int> s(nums.begin(), nums.end());
        std::vector<int> arr;
        for (int i = l; i <= r; i++) {
            if (!s.count(i)) {
                arr.push_back(i);
            }
        }

        return arr;
    }
};