class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) {
            return "";
        }

        string ans(num, '0');
        for (int i = 0; i < num && sum > 0; i++) {
            int x = std::min(9, sum);
            ans[i] = (x + '0');
            sum -= x;
        }

        return ans;
    }
};