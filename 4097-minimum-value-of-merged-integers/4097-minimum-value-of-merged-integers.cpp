class Solution {
public:
    using ll = long long;

    int minMergedInteger(vector<int>& nums) {
        std::vector<ll> arr;
        for (int i = 0; i < nums.size(); i += 2) {
            std::string s = std::to_string(nums[i]) + std::to_string(nums[i + 1]);
            arr.push_back(std::stol(s));
        }

        ll mn = *std::min_element(arr.begin(), arr.end());

        return mn;
    }
};