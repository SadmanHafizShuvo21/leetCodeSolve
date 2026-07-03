class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) {
            swap(a, b);
        }

        int x = a.size(), y = b.size(), c = 0;
        b = string (x - y, '0') + b;
        string s;
        int cry = 0;
        for (int i = a.size() - 1; i >= 0; i--) {
            int add = (a[i] - '0') + (b[i] - '0') + c;
            if (add == 3) {
                s += '1';
                c = 1;
            }
            else if (add == 2) {
                s += '0';
                c = 1;
            }
            else {
                s += (add + '0');
                c = 0;
            }
        }

        if (c == 1) {
            s += '1';
        }
        reverse(s.begin(), s.end());
        return s;
    }
};