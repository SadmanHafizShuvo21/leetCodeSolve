class Solution {
public:
    using ll = long long;
    int reverseDegree(string s) {
        ll ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans += (26 - (s[i] - 'a')) * (i + 1);
        }

        return ans;
    }
};