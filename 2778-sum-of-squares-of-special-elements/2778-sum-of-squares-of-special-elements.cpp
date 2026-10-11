class Solution {
public:
    using ll = long long;

    ll digitSquare(ll x) {
        return 1LL * x * x;
    } 
    int sumOfSquares(vector<int>& nums) {
        ll ans = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            ans += (n % (i + 1) ? 0 : digitSquare(nums[i]));
        }

        return ans;
    }
};