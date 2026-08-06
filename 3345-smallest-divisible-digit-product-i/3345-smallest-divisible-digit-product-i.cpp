class Solution {
public:
    int digitProduct(int n) {
        int ans = 1;
        while (n > 0) {
            int rem = n % 10;
            ans *= rem;
            n /= 10;
        }

        return ans;
    }

    int smallestNumber(int n, int t) {
        while (true) {
            int val = digitProduct(n);
            if (val % t == 0) {
                return n;
            }
            n++;
        }
    }
};