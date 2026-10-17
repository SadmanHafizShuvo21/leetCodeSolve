class Solution {
public:
    using ll = long long;

    ll digitSum(ll n) {
        ll sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(std::vector<int>& nums) {
        ll n = nums.size();
        std::vector<std::pair<ll, ll>> a;
        for (int i = 0; i < n; i++) {
            a.push_back({digitSum(nums[i]), nums[i]});
        }

        std::sort(a.begin(), a.end());

        std::unordered_map<ll, ll> mp;
        for (int i = 0; i < n; i++) {
            mp[a[i].second] = i;
        }

        std::vector<bool> vis(n, false);
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] || mp[nums[i]] == i) {
                continue;
            }

            ll cnt = 0, j = i;
            while (!vis[j]) {
                vis[j] = true;
                j = mp[nums[j]];
                cnt++;
            }

            ans += cnt - 1;
        }

        return ans;
    }
};