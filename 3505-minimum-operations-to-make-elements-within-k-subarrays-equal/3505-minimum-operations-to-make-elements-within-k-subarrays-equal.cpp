
class Solution {
    using ll = long long;
    const ll inf = 1e18;


    std::multiset<int> lo, hi;
    ll sumLo = 0, sumHi = 0;
    void balance() {
        while (lo.size() > hi.size() + 1) {
            int v = *lo.rbegin();
            lo.erase(lo.find(v));
            sumLo -= v;

            hi.insert(v);
            sumHi += v;
        }

        while (lo.size() < hi.size()) {
            int v = *hi.begin();
            hi.erase(hi.find(v));
            sumHi -= v;

            lo.insert(v);
            sumLo += v;
        }
    }

    void add(int v) {
        if (lo.empty() || v <= *lo.rbegin()) {
            lo.insert(v);
            sumLo += v;
        } 
        else {
            hi.insert(v);
            sumHi += v;
        }

        balance();
    }

    void remove(int v) {
        auto it = lo.find(v);

        if (it != lo.end()) {
            lo.erase(it);
            sumLo -= v;
        } 
        else {
            it = hi.find(v);
            hi.erase(it);
            sumHi -= v;
        }

        balance();
    }

    ll getCost() {
        ll med = *lo.rbegin();
        return med * lo.size() - sumLo + sumHi - med * hi.size();
    }

    std::vector<ll> getCosts(std::vector<int>& nums, int x) {
        int n = nums.size();
        std::vector<ll> cost(n - x + 1);

        lo.clear();
        hi.clear();
        sumLo = sumHi = 0;

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1)
                cost[i - x + 1] = getCost();
        }

        return cost;
    }

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        std::vector<ll> cost = getCosts(nums, x);
        std::vector<ll> dp(n + 1, 0), ndp(n + 1, inf);

        for (int j = 1; j <= k; j++) {
            std::fill(ndp.begin(), ndp.end(), inf);

            for (int i = 1; i <= n; i++) {
                ndp[i] = ndp[i - 1];

                if (i >= x && dp[i - x] != inf) {
                    ndp[i] = std::min( ndp[i], dp[i - x] + cost[i - x]);
                }
            }

            dp.swap(ndp);
        }

        return dp[n];
    }
};
