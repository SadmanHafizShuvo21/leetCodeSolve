class Solution {
public:
    using ll = long long;
    int minChanges(string s) {
        ll n = s.size(), ans = 0;
        for (int i = 0; i < n - 1; i += 2) {
            ans +=(s[i] != s[i + 1]);
        }

        return ans;
    }
};