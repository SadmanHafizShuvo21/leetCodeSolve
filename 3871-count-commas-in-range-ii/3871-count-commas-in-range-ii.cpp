class Solution {
public:
    using ll = unsigned long long;

    ll countCommas(ll n) {
        ll arr[6] = {1000, 1000000, 1000000000, 1000000000000, 1000000000000000, 1000000000000000000};
    
        ll k = 0;
        for (auto x : arr) {
            k += (n >= x);
        }

        return 1LL * k * (n + 1) - (arr[k] - 1000) / 999;
    }
};