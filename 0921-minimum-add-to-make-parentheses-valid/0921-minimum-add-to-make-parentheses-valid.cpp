class Solution {
public:
    using ll = long long;
    int minAddToMakeValid(string s) {
        ll cnt = 0, ans = 0;
        for (auto x : s) {
            if (x == '(') {
                cnt++;
            }
            else {
                cnt--;
            }

            if (cnt < 0) {
                ans++;
                cnt++;
            }
        }

        return ans + cnt;
    }
};