class Solution {
public:
    using ll = long long;
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        ll n = nums.size(), ans = 0, cost = 0, j = n - 1;
        std::deque<std::pair<ll, ll>> dq;
        for (int i = n - 1; i >= 0; i--) {
            ll x = nums[i], cnt = 1;
            while (!dq.empty() && dq.back().first < x) {
                auto [v, c] = dq.back();
                dq.pop_back();

                cnt += c;
                cost += (x - v) * c;
            }

            dq.push_back({x, cnt});
            while (cost > k) {
                auto [v, c] = dq.front();
                dq.pop_front();
                cost -= v - nums[j];
                j--;
                if (c > 1) {
                    dq.push_front({v, c - 1});
                }
            }
            ans += j - i + 1;
        }
        return ans;
    }
};