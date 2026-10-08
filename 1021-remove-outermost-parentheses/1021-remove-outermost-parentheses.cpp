class Solution {
public:
    using ll = long long;
    string removeOuterParentheses(string s) {
        std::string str;

        ll cnt = 0;
        for (auto c : s) {
            if (c == '(') {
                if (cnt > 0) {
                    str.push_back(c);
                }
                cnt++;
            }
            else {
                cnt--;
                if (cnt > 0) {
                    str.push_back(c);
                }
            }
        }

        return str;
    }
};