class Solution {
public:
    using ll = long long;
    int maxActiveSectionsAfterTrade(string s) {
        ll cnt1 = std::count(s.begin(), s.end(), '1');

        s = '1' + s + '1';
        std::vector<std::pair<ll, ll>> pr;
        for (char c : s) {
            if (pr.empty() || pr.back().first != c) {
                pr.push_back({c, 1});
            } 
            else {
                pr.back().second++;
            }
        }

        ll best = 0;
        for (int i = 1; i + 1 < pr.size(); i++) {
            if (pr[i].first == '1' && pr[i - 1].first == '0' && pr[i + 1].first == '0') {
                best = max(best, pr[i - 1].second + pr[i + 1].second);
            }
        }

        return cnt1 + best;
    }
};