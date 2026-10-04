class Solution {
public:
    using ll = long long;
    int minRotations(string s) {
        ll ans = 0, ls = 0;
        for (int i = 0; i < s.size(); i++) {
            ll x = s[i] - '0';
            ans += std::min(std::abs(x - ls), (10 - std::abs(x - ls)));
            ls = x;
        }

        return ans;
    }
};