
class Solution {
public:
    std::unordered_set<std::string> st;

    void dfs(std::string &s, int pos, int left, int right, int bal, std::string cur) {
        if (pos == s.size()) {
            if (left == 0 && right == 0 && bal == 0) {
                st.insert(cur);
            }
            return;
        }

        if (s[pos] == '(') {
            if (left > 0) {
                dfs(s, pos + 1, left - 1, right, bal, cur);
            }

            dfs(s, pos + 1, left, right, bal + 1, cur + '(');
        }
        else if (s[pos] == ')') {
            if (right > 0) {
                dfs(s, pos + 1, left, right - 1, bal, cur);
            }

            if (bal > 0) {
                dfs(s, pos + 1, left, right, bal - 1, cur + ')');
            }
        }
        else {
            dfs(s, pos + 1, left, right, bal, cur + s[pos]);
        }
    }

    std::vector<std::string> removeInvalidParentheses(std::string s) {
        int left = 0, right = 0;

        for (char c : s) {
            if (c == '(') {
                left++;
            }
            else if (c == ')') {
                if (left > 0) {
                    left--;
                }
                else {
                    right++;
                }
            }
        }

        dfs(s, 0, left, right, 0, "");

        return std::vector<std::string>(st.begin(), st.end());
    }
};
