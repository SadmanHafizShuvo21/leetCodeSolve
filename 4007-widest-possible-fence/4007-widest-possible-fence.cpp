class Solution {
public:
    using ll = long long;

    int maximumWidth(vector<int>& planks) {
        std::unordered_map<ll, ll> h, w;
        for (auto x : planks) {
            h[x]++;
            w[x]++;
        }

        for (auto &[a, cnta] : h) {
            for (auto &[b, cntb] : h) {
                if (a < b) {
                    w[a + b] += std::min(cnta,  cntb);
                }
                else if (a == b) {
                    w[a + b] += cnta / 2;
                }
            }
        }

        ll ans = 0;
        for (auto [x, cnt] : w) {
            ans = std::max(ans, cnt);
        }

        return ans;
    }
};