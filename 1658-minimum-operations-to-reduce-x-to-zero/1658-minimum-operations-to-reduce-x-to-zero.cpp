class Solution {
public:
    using ll = long long;
    int minOperations(vector<int>& nums, int x) {
        ll n = nums.size();

        ll sum = std::accumulate(nums.begin(), nums.end(), 0LL);
        if (x > sum) {
            return -1;
        }
        if (sum == x) {
            return n;
        }

        ll k = sum - x, cur = 0, j = 0, mx = -1;
        for (int i = 0; i < n; i++) {
            cur += nums[i];

            while (i >= j && cur > k) {
                cur -= nums[j];
                j++;
            }

            if (cur == k) {
                mx = std::max(mx, i - j + 1);
            }
        }

        return mx == -1 ? -1 : n - mx;
    }
};