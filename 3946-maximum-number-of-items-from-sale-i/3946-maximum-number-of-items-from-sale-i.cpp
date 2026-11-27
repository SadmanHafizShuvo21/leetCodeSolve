
class Solution {
public:
    using ll = long long;
    const ll neg = -(1LL << 60);
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size(), mx = 1500;
        std::vector<int> cnt(mx + 1, 0), ways(mx + 1, 0);
        for (auto &v : items) {
            cnt[v[0]]++;
        }

        for (int i = 1; i <= mx; i++) {
            for (int j = i; j <= mx; j += i) {
                ways[i] += cnt[j];
            }
        }
    
        std::vector<long long> dp(budget + 1, neg);
        dp[0] = 0;
        for (auto &v : items) {
            int f = v[0], p = v[1];
            int w = ways[f] - 1;

            std::vector<long long> ndp = dp;
            for (int r = 0; r < p && r <= budget; r++) {
                ll best = neg;

                for (int b = r, t = 0; b <= budget; b += p, t++) {
                    if (t > 0 && dp[b - p] != neg) {
                        best = std::max(best, dp[b - p] - (t - 1));
                    }

                    if (best != neg) {
                        ndp[b] = std::max(ndp[b], best + w + t);
                    }
                }
            }

            dp = ndp;
        }

        return *std::max_element(dp.begin(), dp.end());
    }
};
