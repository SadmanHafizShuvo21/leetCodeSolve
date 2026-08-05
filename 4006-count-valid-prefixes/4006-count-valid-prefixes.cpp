class Solution {
public:
    int countValidPrefixes(string s) {
        int ans = 0, cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                cnt++;
            }
            else {
                cnt--;
            }
            ans += (abs(cnt) <= 1);
        }

        return ans;
    }
};