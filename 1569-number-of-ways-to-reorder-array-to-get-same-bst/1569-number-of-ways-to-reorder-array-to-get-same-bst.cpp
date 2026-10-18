
class Solution {
public:
    using ll = long long;
    const ll mod = 1e9 + 7;

    ll C[1005][1005];

    ll solve(std::vector<int>& nums) {
        ll n = nums.size();

        if (n <= 2) {
            return 1;
        }

        std::vector<int> left, right;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0]) {
                left.push_back(nums[i]);
            } 
            else {
                right.push_back(nums[i]);
            }
        }

        ll l = solve(left), r = solve(right);
        return C[n - 1][left.size()] * l % mod * r % mod;
    }

    int numOfWays(std::vector<int>& nums) {
        ll n = nums.size();
        for (int i = 0; i <= n; i++) {
            C[i][0] = C[i][i] = 1;

            for (int j = 1; j < i; j++) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
            }
        }

        return (solve(nums) - 1 + mod) % mod;
    }
};
