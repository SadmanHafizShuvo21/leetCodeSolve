class Solution {
public:
    using ll = long long;
    long long gcdSum(vector<int>& nums) {
        int n = nums.size(), mx = 0;
        vector<int> pref(n, 0);
        for (int i = 0; i < nums.size(); i++) {
            mx = std::max(mx, nums[i]);
            pref[i] = std::gcd(mx, nums[i]);
        }

        sort(pref.begin(), pref.end());
        
        ll l = 0, r = n - 1, ans = 0;
        while (l < r) {
            ans += gcd(pref[l], pref[r]);
            l++;
            r--;
        }

        return ans;
    }
};