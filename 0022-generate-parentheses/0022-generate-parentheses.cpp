class Solution {
public:
    using ll = long long;
    vector<string> ans;

    void dfs(string s, int open, int close, int n) {
        if (s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }

        if (open < n) {
            dfs(s + '(', open + 1, close, n);
        }

        if (close < open) {
            dfs(s + ')', open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        ans.clear();
        
        dfs("", 0, 0, n);
        return ans;
    }
};