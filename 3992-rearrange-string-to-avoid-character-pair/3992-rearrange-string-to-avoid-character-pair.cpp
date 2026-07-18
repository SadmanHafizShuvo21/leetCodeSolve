class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        sort(s.begin(), s.end());

        if (x > y) {
            return s;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};