class Solution {
public:
    using ll = long long;
    string reverseParentheses(string s) {
        std::vector<std::string> st;
        std::string cur;

        for (auto c : s) {
            if (c == '(') {
                st.push_back(cur);
                cur.clear();
            }
            else if (c == ')') {
                std::reverse(cur.begin(), cur.end());
                cur = st.back() + cur;
                st.pop_back();
            }
            else {
                cur += c;
            }
        }

        return cur;
    }
};