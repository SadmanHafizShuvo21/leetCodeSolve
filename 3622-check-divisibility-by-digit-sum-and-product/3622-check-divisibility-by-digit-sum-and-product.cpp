class Solution {
public:
    using ll = long long;
    int digitSum(int n) {
        int sum = 0;
        while(n > 0) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }

    int digitProduct(int n) {
        int mul = 1;
        
        while(n > 0) {
            int rem = n % 10;
            if (rem == 0) {
                return 0;
            }
            mul *= rem;

            n /= 10;
        }
        return mul;
    }
    bool checkDivisibility(int n) {
        int sum = digitSum(n);
        int mul = digitProduct(n);

        return n % (sum + mul) == 0;
    }
};