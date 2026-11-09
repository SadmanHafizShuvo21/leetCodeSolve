class Solution {
public:
    using ll = long long;
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        ll n = s1.size();
        std::string s, t;
        std::vector<std::vector<std::string>> pr;
        for (int i = 0; i < n; i++) {
            if (s1[i] == s2[i]) {
                if (!s.empty()) {
                    pr.push_back({s, t});
                    t.clear();
                    s.clear();
                }
                continue;
            }
            else {
                s += s1[i];
                t += s2[i];
            }
        }
        if (!s.empty()) {
            pr.push_back({s, t});
            t.clear();
            s.clear();
        }

        return pr;
    }
};