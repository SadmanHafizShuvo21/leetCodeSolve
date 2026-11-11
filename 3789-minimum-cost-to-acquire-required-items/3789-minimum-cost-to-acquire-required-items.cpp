
class Solution {
public:
    using ll = long long;

    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        ll ans = 0;

        if (costBoth >= cost1 + cost2) {
            ans = 1LL * need1 * cost1 + 1LL * need2 * cost2;
        }
        else {
            ll k = std::min(need1, need2);

            ans = k * costBoth;
            if (need1 > need2) {
                ans += 1LL * (need1 - need2) * std::min(cost1, costBoth);
            }
            else {
                ans += 1LL * (need2 - need1) * std::min(cost2, costBoth);
            }
        }

        return ans;
    }
};
