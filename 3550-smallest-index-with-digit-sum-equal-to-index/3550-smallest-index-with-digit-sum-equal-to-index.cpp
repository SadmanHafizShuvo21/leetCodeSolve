class Solution {
public:
    using ll = long long;

    ll digitSum(ll x) {
        ll sum = 0;
        while (x > 0) {
            ll rem = x % 10;
            sum += rem;
            x /= 10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (digitSum(nums[i]) == i) {
                return i;
            }
        }

        return -1;
    }
};