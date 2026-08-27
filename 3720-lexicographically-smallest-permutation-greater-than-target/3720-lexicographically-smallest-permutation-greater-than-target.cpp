class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26);

        for (char c : s) cnt[c - 'a']++;

        int i = 0;

        while (i < n && cnt[target[i] - 'a']) {
            cnt[target[i] - 'a']--;
            i++;
        }

        while (i >= 0) {
            if (i < n) {
                for (int c = target[i] - 'a' + 1; c < 26; c++) {
                    if (cnt[c]) {
                        string ans = target.substr(0, i);
                        ans += char('a' + c);
                        cnt[c]--;

                        for (int j = 0; j < 26; j++) {
                            ans += string(cnt[j], char('a' + j));
                        }

                        return ans;
                    }
                }
            }

            if (i == 0) {
                break;
            }
            i--;
            cnt[target[i] - 'a']++;
        }

        return "";
    }
};