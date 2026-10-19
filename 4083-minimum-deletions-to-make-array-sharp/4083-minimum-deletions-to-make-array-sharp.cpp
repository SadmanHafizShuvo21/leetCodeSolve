class Solution {
public:
    using ll = long long;
    int minDeletions(vector<int>& nums) {
        ll ans = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            ans += (nums[i] == nums[i + 1]);
        }
        
        return ans;
    }
};