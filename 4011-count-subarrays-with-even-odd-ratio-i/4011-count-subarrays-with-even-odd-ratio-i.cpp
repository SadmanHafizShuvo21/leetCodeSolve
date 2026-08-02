class Solution {
public:
    using ll = long long;
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        ll n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            ll ev = 0, od = 0;
            
            for (int j = i; j < n; j++) {
                if (nums[j] % 2) {
                    od++;
                }
                else {
                    ev++;
                }

                ans += (od > 0 && 1LL * a * od >= 1LL * b * ev);
            }
        }

        return ans;
    }
};