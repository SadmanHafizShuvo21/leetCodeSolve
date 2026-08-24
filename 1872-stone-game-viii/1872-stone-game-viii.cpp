class Solution {
public:
    using ll = long long;
    int stoneGameVIII(vector<int>& st) {
        ll n = st.size();
        std::vector<ll> pref(n);
        pref[0] = st[0];
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + st[i];
        }

        ll dp = pref[n - 1];
        for (int i = n - 2; i > 0; i--) {
            dp = std::max(dp, pref[i] - dp);
        }

        return dp;
    }
};