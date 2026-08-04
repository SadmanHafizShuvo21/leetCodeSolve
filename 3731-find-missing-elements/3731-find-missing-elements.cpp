class Solution {
public:
    using ll = long long;
    vector<int> findMissingElements(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        ll l = nums[0], r = nums.back();

        std::set<int> s(nums.begin(), nums.end());
        std::vector<int> arr;
        for (int i = l; i <= r; i++) {
            if (s.contains(i)) {
                continue;
            }

            arr.push_back(i);
        }

        return arr;
    }
};