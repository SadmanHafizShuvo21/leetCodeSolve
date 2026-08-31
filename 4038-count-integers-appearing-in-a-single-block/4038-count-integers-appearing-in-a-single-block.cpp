class Solution {
public:
    using ll = long long;

    int countSpecialIntegers(vector<int>& nums) {
        ll n = nums.size();

        map<ll, ll> mp;
        mp[nums[0]]++;
        for (int i = 1; i < n; i++) {
            if (i > 0 && nums[i] != nums[i - 1]) {
                mp[nums[i]]++;
            }
        }

        ll ans = 0;
        for (auto [x, cnt] : mp) {
            ans += (cnt == 1);
        }

        return ans;
    }
};