class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum = 0;
        string s;
        while(n > 0) {
            int rem = n % 10;
            if (rem != 0) {
                s += (rem + '0');
            }
            sum += rem;
            n /= 10;
        }
        reverse(s.begin(), s.end());
        if (s.empty()) {
            return 0;
        }

        int num = stoi(s);
        return 1LL * num * sum;
    }
};