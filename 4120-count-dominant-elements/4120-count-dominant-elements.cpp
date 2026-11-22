class Solution {
public:
    using ll = long long;
    int countDominantElements(vector<int>& nums) {
        ll n = nums.size(), ans = 0;

        if (n == 1) {
            return 1;
        }

        if (n == 2) {
            return nums[0] == nums[1] ? 2 : 1;
        }
        
        if (nums[0] >= nums[1]) {
            ans++;
        }

        for (int i = 1; i < n - 1; i++) {
            ll mid = (nums[i - 1] + nums[i + 1]);
            ans += (2LL * nums[i] >= mid);
        }

        if (nums[n - 1] >= nums[n - 2]) {
            ans++;
        }

        return ans;
    }
};