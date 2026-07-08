class Solution {
public:
    static constexpr long long mod = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& q) {
        vector<int> pos, val;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                val.push_back(s[i] - '0');
            }
        }

        int n = val.size();
        vector<long long> pref(n + 1), sum(n + 1), p10(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            p10[i] = (p10[i - 1] * 10) % mod;
        }

        for (int i = 0; i < n; i++) {
            pref[i + 1] = (pref[i] * 10 + val[i]) % mod;
            sum[i + 1] = (sum[i] + val[i]) % mod;
        }

        vector<int> ans;
        for (auto& x : q) {
            int l = x[0];
            int r = x[1];

            int left = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int right = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            if (left > right) {
                ans.push_back(0);
                continue;
            }

            int len = right - left + 1;
            long long str = (pref[right + 1] - pref[left] * p10[len] % mod + mod) % mod;
            long long digit_sum = (sum[right + 1] - sum[left] + mod) % mod;

            ans.push_back(str * digit_sum % mod);
        }

        return ans;
    }
};