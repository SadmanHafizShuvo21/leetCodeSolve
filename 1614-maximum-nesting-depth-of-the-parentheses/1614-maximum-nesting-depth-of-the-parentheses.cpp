class Solution {
public:
    using ll = long long;
    int maxDepth(string s) {
        ll cnt = 0, mx = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                cnt++;
            }
            else if (s[i] == ')') {
                cnt--;
            }
            else {
                continue;
            }

            mx = std::max(cnt, mx);
        }

        return mx;
    }
};