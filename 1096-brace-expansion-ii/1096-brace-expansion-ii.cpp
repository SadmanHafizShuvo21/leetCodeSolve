class Solution {
public:
    using ll = long long;

    std::set<string> merge(std::set<string> a, std::set<string> b) {
        std::set<string> ans;

        for (auto &x : a) {
            for (auto &y : b) {
                ans.insert(x + y);
            }
        }

        return ans;
    }

    std::set<string> solve(string &s, int &i) {
        std::set<string> ans, cur;

        cur.insert("");
        while (i < s.size() && s[i] != '}') {
            if (s[i] == ',') {
                for (auto &x : cur) {
                    ans.insert(x);
                }

                cur.clear();
                cur.insert("");
                i++;
            }
            else if (s[i] == '{') {
                i++;

                std::set<string> x = solve(s, i);
                cur = merge(cur, x);

                i++;
            }
            else {
                std::set<string> x;
                x.insert(string(1, s[i]));

                cur = merge(cur, x);
                i++;
            }
        }

        for (auto &x : cur) {
            ans.insert(x);
        }

        return ans;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;
        std::set<string> ans = solve(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};