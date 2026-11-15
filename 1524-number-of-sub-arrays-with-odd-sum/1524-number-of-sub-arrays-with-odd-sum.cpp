
class Solution {
public:
    using ll = long long;
    const ll mod = 1e9 + 7;

    int numOfSubarrays(std::vector<int>& arr) {
        ll even = 1, odd = 0, sum = 0, ans = 0;
        for (int x : arr) {
            sum += x;

            if (sum % 2) {
                ans = (ans + even) % mod;
                odd++;
            }
            else {
                ans = (ans + odd) % mod;
                even++;
            }
        }

        return ans;
    }
};
