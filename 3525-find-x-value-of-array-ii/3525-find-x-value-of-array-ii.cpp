class Solution {
public:
    struct SegTree {
        int n, k;
        std::vector<int> prod;
        std::vector<std::array<int, 5>> st;

        SegTree(int _n, int _k) {
            n = _n;
            k = _k;
            prod.assign(4 * n + 5, 0);
            st.assign(4 * n + 5, {});
        }

        void build(std::vector<int>& a, int v, int l, int r) {
            if (l == r) {
                prod[v] = a[l] % k;
                st[v].fill(0);
                st[v][prod[v]] = 1;
                return;
            }

            int m = (l + r) / 2;

            build(a, v * 2, l, m);
            build(a, v * 2 + 1, m + 1, r);

            merge(v);
        }

        void merge(int v) {
            prod[v] = (prod[v * 2] * prod[v * 2 + 1]) % k;
            st[v].fill(0);

            for (int i = 0; i < k; i++) {
                st[v][i] += st[v * 2][i];

                for (int j = 0; j < k; j++) {
                    int x = (prod[v * 2] * j) % k;

                    if (x == i) {
                        st[v][i] += st[v * 2 + 1][j];
                    }
                }
            }
        }

        void update(int v, int l, int r, int pos, int val) {
            if (l == r) {
                prod[v] = val % k;
                st[v].fill(0);
                st[v][prod[v]] = 1;
                return;
            }

            int m = (l + r) / 2;

            if (pos <= m) {
                update(v * 2, l, m, pos, val);
            }
            else {
                update(v * 2 + 1, m + 1, r, pos, val);
            }

            merge(v);
        }

        std::pair<int, std::array<int, 5>> query(int v, int l, int r, int ql, int qr) {

            if (ql <= l && r <= qr) {
                return {prod[v], st[v]};
            }

            int m = (l + r) / 2;

            if (qr <= m) {
                return query(v * 2, l, m, ql, qr);
            }

            if (ql > m) {
                return query(v * 2 + 1, m + 1, r, ql, qr);
            }

            auto a = query(v * 2, l, m, ql, qr);
            auto b = query(v * 2 + 1, m + 1, r, ql, qr);

            int p = (a.first * b.first) % k;

            std::array<int, 5> cnt{};
            cnt.fill(0);

            for (int i = 0; i < k; i++) {
                cnt[i] += a.second[i];

                for (int j = 0; j < k; j++) {
                    if (i == (a.first * j) % k) {
                        cnt[i] += b.second[j];
                    }
                }
            }

            return {p, cnt};
        }
    };

    std::vector<int> resultArray(std::vector<int>& nums, int k, std::vector<std::vector<int>>& queries
    ) {
        int n = nums.size();
        SegTree seg(n, k);
        seg.build(nums, 1, 0, n - 1);

        std::vector<int> ans;

        for (auto &q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            seg.update(1, 0, n - 1, index, value);

            auto res = seg.query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.second[x]);
        }

        return ans;
    }
};