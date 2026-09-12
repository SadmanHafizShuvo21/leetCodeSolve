#include <bits/stdc++.h>
using ll = long long;
using ld = double;
using lld = long double;
using llx = __int128;
const ll inf = 1e18;
const ll N = 500000;
const ll error = 1e-6;
const lld pi = acosl(-1.0L);

class Solution {
public:
    std::vector<int> maximumWeight(std::vector<std::vector<int>>& intervals) {
        ll n = intervals.size();
        std::vector<std::array<ll, 3>> a(n);
        for (ll i = 0; i < n; i++) {
            a[i] = {intervals[i][0], intervals[i][1], i};
        }

        std::sort(a.begin(), a.end(), [](auto &x, auto &y) {
            return x[1] < y[1];
        });

        std::vector<ll> pre(n);
        for (ll i = 0; i < n; i++) {
            ll l = a[i][0];
            ll lo = 0, hi = i - 1, p = -1;

            while (lo <= hi) {
                ll m = (lo + hi) / 2;

                if (a[m][1] < l) {
                    p = m;
                    lo = m + 1;
                } 
                else {
                    hi = m - 1;
                }
            }

            pre[i] = p;
        }

        std::vector<std::vector<ll>> dp[5];
        for (ll k = 0; k <= 4; k++)
            dp[k].resize(n + 1);

        auto better = [&](std::vector<ll> &x, std::vector<ll> &y) {
            ll sx = 0, sy = 0;
            for (ll i : x) sx += intervals[i][2];
            for (ll i : y) sy += intervals[i][2];

            if (sx != sy) return sx > sy;
            return x < y;
        };

        for (ll k = 1; k <= 4; k++) {
            for (ll i = 1; i <= n; i++) {
                dp[k][i] = dp[k][i - 1];

                std::vector<ll> v = dp[k - 1][pre[i - 1] + 1];
                v.push_back(a[i - 1][2]);
                std::sort(v.begin(), v.end());

                if (better(v, dp[k][i]))
                    dp[k][i] = v;
            }
        }

        return std::vector<int>(dp[4][n].begin(), dp[4][n].end());
    }
};