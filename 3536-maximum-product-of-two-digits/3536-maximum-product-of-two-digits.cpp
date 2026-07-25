class Solution {
public:
    using ll = long long;
    const ll inf = 1e9;

    int maxProduct(int n) {
        vector<ll> ans;
        while(n > 0) {
            ll rem = n % 10;
            ans.push_back(rem);
            n /= 10;
        }

        sort(ans.rbegin(), ans.rend());

        return ans[0] * ans[1];
    }
};