class Solution {
public:
    using ll = long long;

    int largestInteger(int n, int s) {
        if (s > n * 9 || n == 0) {
            return -1;
        }
        
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ll mx = std::min(9, s);
            
            ans = (10 * ans + mx);
            s -= mx;
        }

        return ans;
    }
};