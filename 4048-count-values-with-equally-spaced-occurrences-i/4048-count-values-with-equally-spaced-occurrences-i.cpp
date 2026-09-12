class Solution {
public:
    using ll = long long;
    int countSpecialIntegers(vector<int>& nums) {
        std::map<ll, ll> mp;
        for (auto x : nums) {
            mp[x]++;
        }

        std::vector<ll> arr;
        for (auto [x, cnt] : mp) {
            if (cnt == 3) {
                arr.push_back(x);
            }
        }


        ll cnt = 0;
        for (int i = 0; i < arr.size(); i++) {
            std::vector<ll> a;
            for (int j = 0; j < nums.size(); j++) {
                if (arr[i] == nums[j]) {
                    a.push_back(j);
                }
            }
            cnt += (a[2] - a[1] == a[1] - a[0]);
            std::fill(a.begin(), a.end(), 0);
        }

        return cnt;
    }
};