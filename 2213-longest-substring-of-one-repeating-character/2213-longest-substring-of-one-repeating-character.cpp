class Solution {
public:

    struct Node {
        int len;
        int pref, suff, best;
        char lc, rc;

        Node() {
            len = 0;
            pref = suff = best = 0;
            lc = rc = '#';
        }

        Node(char c) {
            len = 1;
            pref = suff = best = 1;
            lc = rc = c;
        }
    };

    struct SegTree {
        int n;
        vector<Node> st;

        SegTree(int _n = 0) {
            init(_n);
        }

        void init(int _n) {
            n = _n;
            st.assign(4 * n + 5, Node());
        }

        Node merge(Node a, Node b) {
            if (a.len == 0) return b;
            if (b.len == 0) return a;

            Node res;

            res.len = a.len + b.len;
            res.lc = a.lc;
            res.rc = b.rc;

            res.pref = a.pref;
            res.suff = b.suff;
            res.best = max(a.best, b.best);

            if (a.rc == b.lc) {
                res.best = max(res.best, a.suff + b.pref);
                if (a.pref == a.len) {
                    res.pref = a.len + b.pref;
                }

                if (b.suff == b.len) {
                    res.suff = b.len + a.suff;
                }
            }

            return res;
        }

        void build(int v, int l, int r, string &s) {
            if (l == r) {
                st[v] = Node(s[l]);
                return;
            }

            int m = (l + r) / 2;
            build(v * 2, l, m, s);
            build(v * 2 + 1, m + 1, r, s);

            st[v] = merge(st[v * 2], st[v * 2 + 1]);
        }

        void update(int v, int l, int r, int pos, char c) {
            if (l == r) {
                st[v] = Node(c);
                return;
            }

            int m = (l + r) / 2;
            if (pos <= m) {
                update(v * 2, l, m, pos, c);
            }
            else {
                update(v * 2 + 1, m + 1, r, pos, c);
            }

            st[v] = merge(st[v * 2], st[v * 2 + 1]);
        }
    };

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size(), q = queryIndices.size();

        SegTree seg(n);

        seg.build(1, 0, n - 1, s);

        vector<int> ans;
        for (int i = 0; i < q; i++) {
            int idx = queryIndices[i];
            char c = queryCharacters[i];

            seg.update(1, 0, n - 1, idx, c);

            ans.push_back(seg.st[1].best);
        }

        return ans;
    }
};