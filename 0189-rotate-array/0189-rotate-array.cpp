class Solution {
public:
    using ll = long  long;

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k %= n;
        std::rotate(nums.rbegin(), nums.rbegin() + k, nums.rend());
        // return nums;
    }
};