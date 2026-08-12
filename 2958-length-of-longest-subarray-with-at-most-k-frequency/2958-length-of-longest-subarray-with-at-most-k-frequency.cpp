class Solution {
public:
    using ll = long long;

    int maxSubarrayLength(vector<int>& nums, int k) {
        ll ans = 0, l = 0;
        std::map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;

            while (mp[nums[i]] > k) {
                mp[nums[l]]--;
                l++;
            }

            ans = max(ans, i - l + 1);
        }

        return ans;
    }
};