class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> f(26);

        for (char c : s) {
            f[c - 'a']++;
        }

        int o = 0;
        char md = 0;

        for (int i = 0; i < 26; i++) {
            if (f[i] & 1) {
                o++;
                md = char('a' + i);
            }

            f[i] /= 2;
        }

        if (o > 1) {
            return "";
        }

        int m = n / 2;

        auto get = [&](string h) {
            string ans = h;

            if (n & 1) {
                ans += md;
            }

            string r = h;
            reverse(r.begin(), r.end());

            return ans + r;
        };

        string h;

        for (int i = 0; i < 26; i++) {
            h += string(f[i], char('a' + i));
        }

        if (get(h) > target) {
            return get(h);
        }

        vector<int> c = f;
        bool ok = true;

        for (int i = 0; i < m; i++) {
            int x = target[i] - 'a';

            if (c[x] == 0) {
                ok = false;
                break;
            }

            c[x]--;
        }

        if (ok) {
            string x = target.substr(0, m);

            if (get(x) > target) {
                return get(x);
            }
        }

        for (int p = m - 1; p >= 0; p--) {
            vector<int> c = f;
            bool ok = true;

            for (int i = 0; i < p; i++) {
                int x = target[i] - 'a';

                if (c[x] == 0) {
                    ok = false;
                    break;
                }

                c[x]--;
            }

            if (!ok) {
                continue;
            }

            int x = target[p] - 'a';

            for (int j = x + 1; j < 26; j++) {
                if (c[j] == 0) {
                    continue;
                }

                string a = target.substr(0, p);
                a += char('a' + j);

                c[j]--;

                for (int k = 0; k < 26; k++) {
                    a += string(c[k], char('a' + k));
                }

                return get(a);
            }
        }

        return "";
    }
};