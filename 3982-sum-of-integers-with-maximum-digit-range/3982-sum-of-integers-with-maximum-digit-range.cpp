class Solution {
public:
    int digitSum(int n) {
        int mx = -1e9, mn = 1e9;
        while (n > 0) {
            int rem = n % 10;
            mx = std::max(mx, rem);
            mn = std::min(mn, rem);
            n /= 10;
        }
        return mx - mn;
    }
    int maxDigitRange(vector<int>& nums) {
        int mxCnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            mxCnt = max(mxCnt, digitSum(nums[i]));
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += (mxCnt == digitSum(nums[i]) ? nums[i] : 0);
        }

        return ans;
    }
};