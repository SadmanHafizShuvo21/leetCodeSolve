class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> cnt(26, 0);
        for (auto x : s) {
            cnt[x - 'a']++;
        }

        string str = "";
        string mid = "";
        for (int i = 25; i >= 0; i--) {
            if (cnt[i] == 0) {
                continue;
            }

            int m = cnt[i] / 2;
            if (cnt[i] % 2) {
                mid = (i + 'a');
            }

            str += string(m, 'a' + i);
        }

        string strl = str;
        reverse(strl.begin(), strl.end());
        return strl + mid + str;
    }
};