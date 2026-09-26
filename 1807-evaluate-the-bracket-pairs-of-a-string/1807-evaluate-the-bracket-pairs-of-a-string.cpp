class Solution {
public:
    using ll = long long;

    string evaluate(string s, vector<vector<string>>& knowledge) {
        std::unordered_map<std::string, std::string> mp;

        for (auto &x : knowledge) {
            mp[x[0]] = x[1];
        }

        std::string str;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '(') {
                str += s[i];
                continue;
            }

            int j = i + 1;
            while (s[j] != ')') {
                j++;
            }

            std::string key = s.substr(i + 1, j - i - 1);
            if (mp.count(key)) {
                str += mp[key];
            }
            else {
                str += '?';
            }

            i = j;
        }

        return str;
    }
};