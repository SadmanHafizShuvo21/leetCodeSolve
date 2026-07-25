class Solution {
public:
    int maxProduct(int n) {
        string s = std::to_string(n);
        sort(s.rbegin(), s.rend());

        int l = s.size() - 1;
        return (s[0] - '0') * (s[1] - '0');
    }
};