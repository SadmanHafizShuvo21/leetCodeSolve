
class Solution {
public:
    using ll = long long;
    int minOperations(std::vector<int>& nums) {
        if (is_sorted(nums.begin(), nums.end())) {
            return 0;
        }

        ll n = nums.size();
        ll p = std::find(nums.begin(), nums.end(), 0) - nums.begin();
        
        bool ok = true, ok1 = true;
        for (int i = 1; i < n; i++) {
            ll val = nums[(p + i) % n];

            if (val != i) {
                ok = false;
            }
            if (val != n - i) {
                ok1 = false;
            }

            if (!ok && !ok1) {
                return -1;
            }
        }

        if (ok) {
            return std::min(p, n - p + 2);
        }

        return std::min(n - p, p + 2);
    }
};
