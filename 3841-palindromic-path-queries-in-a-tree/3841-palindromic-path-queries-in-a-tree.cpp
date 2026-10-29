class Solution {
    std::vector<std::vector<int>> adj, up;
    std::vector<int> tin, tout, dep, bit, fenwick;
    int LOG, timer;

    void dfs(int u, int p) {
        tin[u] = timer++;
        up[0][u] = p;

        for (int j = 1; j < LOG; j++) {
            up[j][u] = up[j - 1][up[j - 1][u]];
        }

        for (int v : adj[u]) {
            if (v == p) continue;

            dep[v] = dep[u] + 1;
            dfs(v, u);
        }

        tout[u] = timer;
    }

    void add(int i, int val) {
        for (i++; i <= (int)bit.size(); i += i & -i) {
            fenwick[i] ^= val;
        }
    }

    int pref(int i) {
        int res = 0;

        for (i++; i > 0; i -= i & -i) {
            res ^= fenwick[i];
        }

        return res;
    }

    void update(int i, int val) {
        add(i, val);
    }

    int lca(int u, int v) {
        if (dep[u] < dep[v]) std::swap(u, v);

        int d = dep[u] - dep[v];

        for (int j = 0; j < LOG; j++) {
            if (d & (1 << j)) {
                u = up[j][u];
            }
        }

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[j][u] != up[j][v]) {
                u = up[j][u];
                v = up[j][v];
            }
        }

        return up[0][u];
    }

public:
    std::vector<bool> palindromePath(
        int n,
        std::vector<std::vector<int>>& edges,
        std::string s,
        std::vector<std::string>& queries
    ) {
        adj.assign(n, {});
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        up.assign(LOG, std::vector<int>(n));
        tin.assign(n, 0);
        tout.assign(n, 0);
        dep.assign(n, 0);
        bit.resize(n);
        timer = 0;

        dfs(0, 0);

        for (int i = 0; i < n; i++) {
            bit[i] = 1 << (s[i] - 'a');
        }

        fenwick.assign(n + 1, 0);

        for (int u = 0; u < n; u++) {
            update(tin[u], bit[u]);
            if (tout[u] < n) {
                update(tout[u], bit[u]);
            }
        }

        std::vector<bool> ans;

        for (auto& q : queries) {
            std::stringstream ss(q);
            std::string op;
            int u, v;
            ss >> op >> u;

            if (op == "update") {
                char c;
                ss >> c;

                int nw = 1 << (c - 'a');
                int delta = bit[u] ^ nw;

                update(tin[u], delta);
                if (tout[u] < n) {
                    update(tout[u], delta);
                }

                bit[u] = nw;
                s[u] = c;
            } else {
                ss >> v;

                int w = lca(u, v);
                int mask = pref(tin[u]) ^ pref(tin[v]) ^ bit[w];

                ans.push_back(
                    mask == 0 || (mask & (mask - 1)) == 0
                );
            }
        }

        return ans;
    }
};