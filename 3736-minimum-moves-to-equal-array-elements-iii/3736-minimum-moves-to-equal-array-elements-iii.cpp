class Solution {
public:
    using ll = long long;
    const ll inf = 1e9 + 7;

    int minMoves(vector<int>& nums) {
        ll mx = *std::max_element(nums.begin(), nums.end());

        ll ans = 0;
        for (auto x : nums) {
            ans += (mx - x);
        }

        return ans;
    }
};