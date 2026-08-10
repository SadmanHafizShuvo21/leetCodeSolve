class Solution {
public:
    using ll = long long;
    using lld = long double;

    lld discount(int p, int d) {
        return p * (100 - d) / 100.0;
    }

    double minPrice(vector<int>& pri, vector<int>& dis) {
        sort(pri.rbegin(), pri.rend());
        sort(dis.rbegin(), dis.rend());

        lld ans = 0;
        ll n = pri.size(), m = dis.size();
        for (int i = 0; i < min(n, m); i++) {
            ans += discount(pri[i], dis[i]);
        }

        for (int i = std::min(n, m); i < n; i++) {
            ans += pri[i];
        }

        return ans;
    }
};