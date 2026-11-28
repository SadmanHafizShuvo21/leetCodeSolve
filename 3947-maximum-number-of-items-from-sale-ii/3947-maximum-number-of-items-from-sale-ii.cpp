class Solution {
public:
    using ll = long long;
    const ll inf = 1e18;
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        std::vector<ll> freq(n + 1, 0), cnt(n + 1, 0);

        ll mn = inf;
        for (auto &v : items) {
            freq[v[0]]++;
            mn = std::min(mn, (ll)v[1]);
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                cnt[i] += freq[j];
            }
            cnt[i]--;
        }

        std::sort(items.begin(), items.end(), [](const auto &a, const auto &b) {
            return a[1] < b[1];
        });

        ll ans = 0;
        for (auto &v : items) {
            int f = v[0], p = v[1];
            if (p > 2LL * mn) {
                break;
            }

            ll take = std::min(1LL * cnt[f], 1LL * budget / p);
            ans += 2 * take;
            budget -= take * p;
        }

        ans += budget / mn;
        return ans;
    }
};