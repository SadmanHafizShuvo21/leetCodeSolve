class Solution {
public:
    using ll = long long;
    int scoreOfParentheses(string s) {
        ll ans = 0, cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                cnt++;
            }
            else {
                cnt--;
                if (s[i - 1] == '(') {
                    ans += (1LL << cnt);
                }   
            }
        }

        return ans;
    }
};