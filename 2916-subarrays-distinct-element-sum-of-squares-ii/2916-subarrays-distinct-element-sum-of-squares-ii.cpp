class Solution {
public:
    using ll = long long;
    static constexpr ll mod = 1e9 + 7;

    struct SegTree {
        ll n;
        std::vector<ll> sum, sq, lazy;

        SegTree(int _n = 0) {
            init(_n);
        }

        void init(int _n) {
            n = _n;
            sum.assign(4 * n + 5, 0);
            sq.assign(4 * n + 5, 0);
            lazy.assign(4 * n + 5, 0);
        }

        void apply(int v, int l, int r, ll x) {
            ll len = r - l + 1;
            sq[v] = (sq[v] + 2 * x % mod * sum[v] % mod + x * x % mod * len) % mod;
            sum[v] = (sum[v] + x * len) % mod;
            lazy[v] = (lazy[v] + x) % mod;
        }

        void push(int v, int l, int r) {
            if (lazy[v] == 0 || l == r) {
                return;
            }

            int m = (l + r) / 2;
            apply(v * 2, l, m, lazy[v]);
            apply(2 * v + 1, m + 1, r, lazy[v]);
            lazy[v] = 0;
        }

        void update(int v, int l, int r, int ql, int qr, ll val) {
            if (ql > r || qr < l) {
                return;
            }

            if (ql <= l && r <= qr) {
                apply(v, l, r, val);
                return;
            }

            push(v, l, r);
            int m = (l + r) / 2;

            update(2 * v, l, m, ql, qr, val);
            update(2 * v + 1, m + 1, r, ql, qr, val);

            sum[v] = (sum[2 * v] + sum[2 * v + 1]) % mod;
            sq[v] = (sq[2 * v] + sq[2 * v + 1]) % mod;
        }
    };

    int sumCounts(std::vector<int>& nums) {
        ll n = nums.size(), ans = 0;
        SegTree st(n);

        std::vector<int> last(100001, -1);
        for (int i = 0; i < n; i++) {
            int p = last[nums[i]];

            st.update(1, 0, n - 1, p + 1, i, 1);
            last[nums[i]] = i;

            ans = (ans + st.sq[1]) % mod;
        }

        return ans;
    }
};