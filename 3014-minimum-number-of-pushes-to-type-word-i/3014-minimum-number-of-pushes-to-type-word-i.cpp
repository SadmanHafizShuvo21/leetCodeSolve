class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int m = (n + 7) / 8;

        return 4 * m * (m - 1) + m * (n - (m - 1) * 8);
    }
};