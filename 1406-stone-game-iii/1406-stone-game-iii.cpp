class Solution {
public:
    using ll = long long;
    const ll inf = 1e9 + 7;
    string stoneGameIII(vector<int>& arr) {
        ll n = arr.size();
        vector<ll> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            ll sum = 0;
            dp[i] = -inf;
            
            for (int j = 0; j < 3 && i + j < n; j++) {
                sum += arr[i + j];
                dp[i] = max(dp[i], sum - dp[i + j + 1]);
            }
        }

        return dp[0] > 0 ? "Alice" : dp[0] < 0 ? "Bob" : "Tie";
    }
};