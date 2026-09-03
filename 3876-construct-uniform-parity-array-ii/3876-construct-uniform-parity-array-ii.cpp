class Solution {
public:
    using ll = long long;
    bool uniformArray(vector<int>& nums) {

        if (nums.size() == 1) {
            return true;
        }

        ll mn = *std::min_element(nums.begin(), nums.end());

        bool ok = false;
        for (auto x : nums) {
            if (x & 1) {
                ok = true;
                break;
            }
        }

        if (mn & 1) {
            return true;
        }

        return !ok;
    }
};