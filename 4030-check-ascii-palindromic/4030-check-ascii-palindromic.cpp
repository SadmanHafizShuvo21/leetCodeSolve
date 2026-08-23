class Solution {
public:
    bool check(string s) {
        bool ok = true;
        
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                ok = false;
                break;
            }
            l++;
            r--;
        }

        return ok;
    }

    string toBinary(int num) {
        string bi;

        for (int i = 7; i >= 0; i--) {
            bi += char('0' + ((num >> i) & 1));
        }

        return bi;
    }

    bool isPalindromic(string s) {
        string str;
        for (auto ch : s) {
            int x = int(ch);
            str += toBinary(x);
        }

        return check(str);
    }
};