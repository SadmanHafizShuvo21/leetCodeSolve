class Solution {
public:
    using ll = long long;
    const ll mod = 1e9 + 7;

    ll cal(ll x, ll y) {
        ll val = 1;
        x %= mod;

        while (y > 0) {
            if (y & 1) {
                val = (val * x) % mod;
            }

            x = (x * x) % mod;
            y >>= 1;
        }

        return val;
    }


    ll chk(ll n) {
        ll w = n % 10;
        n /= 10;

        std::string s = std::to_string(n);
        ll l = s.size();

        ll tm = l - w;
        ll mul = 1;
        while (tm > 0) {
            mul *= 10;
            tm--;
        }

        ll x = n / mul;
        ll y = n % mul;

        return cal(x, y);
    }
    int sumDecoded(vector<long long>& nums) {
        ll sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = (sum + chk(nums[i])) % mod;
        }

        return sum;
    }
};