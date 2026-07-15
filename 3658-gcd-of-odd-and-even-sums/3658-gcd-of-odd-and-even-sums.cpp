class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        long long sum1 = n * n;
        long long sum2 = n * (n + 1);
        return gcd(sum1, sum2);
    }
};