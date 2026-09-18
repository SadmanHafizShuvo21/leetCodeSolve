class Solution {
public:
    using ll = long long;
    vector<string> maxNumOfSubstrings(string s) {
        ll n = s.size();
        vector<ll> l(26, n), r(26, -1);
        for (int i = 0; i < n; i++) {
            ll x = s[i] - 'a';
            l[x] = min(l[x], (ll)i);
            r[x] = i;
        }

        vector<pair<ll, ll>> v;
        for (int i = 0; i < 26; i++) {
            if (r[i] == -1) {
                continue;
            }

            ll x = l[i], y = r[i];
            bool ok = true;
            for (int j = x; j <= y; j++) {
                ll z = s[j] - 'a';

                if (l[z] < x) {
                    ok = false;
                    break;
                }

                y = max(y, r[z]);
            }

            if (ok) {
                v.push_back({x, y});
            }
        }

        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        vector<string> ans;
        ll last = -1;
        for (auto [l, r] : v) {
            if (l > last) {
                ans.push_back(s.substr(l, r - l + 1));
                last = r;
            }
        }

        return ans;
    }
};