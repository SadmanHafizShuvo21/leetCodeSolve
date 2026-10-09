class Solution {
public:
    using ll = long long;

    int minInsertions(string s) {
        ll ans = 0, cnt = 0, n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                cnt++;
            }
            else {
                if (i + 1 < n && s[i + 1] == ')') {
                    i++;
                }
                else {
                    ans++;
                }

                if (cnt > 0) {
                    cnt--;
                }
                else {
                    ans++;
                }
            }
        }

        return ans + 2 * cnt;
    }
};