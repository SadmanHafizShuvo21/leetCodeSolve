class Solution {
public:
    using ll = long long;
    vector<long long> resultArray(vector<int>& nums, int k) {
        ll n = nums.size();
        
        vector<ll> ans(k, 0), dp(k, 0);
        for (auto x : nums) {
            vector<long long> ndp(k, 0);
            ll a = x % k;
            ndp[a]++;
            
            for (int r = 0; r < k; r++) {
                if (dp[r]) {
                    ll nr = (r * a) % k;
                    ndp[nr] += dp[r];
                }
            }
            
            dp = ndp;
            for (int r = 0; r < k; r++) {
                ans[r] += dp[r];
            }
        }
        
        return ans;
    }
};