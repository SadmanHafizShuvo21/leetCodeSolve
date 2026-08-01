class Solution {
public:
    using ll = long long;

    bool predictTheWinner(vector<int>& nums) {
        ll n = nums.size();

        if (n % 2 == 0) {
            return true;
        }

        vector<ll> dp(n);
        for (int i = 0; i < n; i++){
            dp[i] = nums[i];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
            }
        }

        return dp[n - 1] >= 0;
    }
};