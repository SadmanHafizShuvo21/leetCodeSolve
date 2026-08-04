class Solution {
public:
    using ll = long long;
    vector<int> findMissingElements(vector<int>& nums) {
        ll mx = *std::max_element(nums.begin(), nums.end());
        ll mn = *std::min_element(nums.begin(), nums.end());

        std::set<int> s(nums.begin(), nums.end());
        std::vector<int> arr;
        for (int i = mn; i <= mx; i++) {
            if (s.contains(i)) {
                continue;
            }

            arr.push_back(i);
        }

        return arr;
    }
};