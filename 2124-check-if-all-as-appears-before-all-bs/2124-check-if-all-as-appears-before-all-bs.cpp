class Solution {
public:
    bool checkString(string s) {
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == s[i + 1]) {
                continue;
            }
            else {
                if (s[i] == 'b') {
                    return false;
                }
            }
        }
        return true;
    }
};