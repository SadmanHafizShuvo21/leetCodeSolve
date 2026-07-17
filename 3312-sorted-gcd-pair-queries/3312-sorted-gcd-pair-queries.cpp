class Solution {
public:
    using ll = long long;
    const int MX = 50000;
    vector<int> gcdValues(vector<int>& nums, vector<ll>& queries) {
        vector<ll> freq(MX + 1, 0);
        for (int x : nums) {
            freq[x]++;
        }

        vector<ll> cnt(MX + 1, 0);
        for (int i = 1; i <= MX; i++) {
            for (int j = i; j <= MX; j += i) {
                cnt[i] += freq[j];
            }
        }

        vector<ll> exact(MX + 1, 0);
        for (int i = MX; i >= 1; i--) {
            exact[i] = cnt[i] * (cnt[i] - 1) / 2;

            for (int j = 2 * i; j <= MX; j += i) {
                exact[i] -= exact[j];
            }
        }

        ll cur = 0;
        vector<ll> pref, val;
        for (int g = 1; g <= MX; g++) {
            if (exact[g] == 0) {
                continue;
            }

            cur += exact[g];
            pref.push_back(cur);
            val.push_back(g);
        }

        vector<int> ans;
        for (ll q : queries) {
            int pos = lower_bound(pref.begin(), pref.end(), q + 1) - pref.begin();
            ans.push_back(val[pos]);
        }

        return ans;
    }
};