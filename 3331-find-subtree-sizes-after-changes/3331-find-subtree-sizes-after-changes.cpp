
#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> answer;
    std::vector<int> last = std::vector<int>(26, -1);
    std::vector<std::vector<int>> adj, tree;

    void dfs1(int u, std::vector<int>& parent, std::string& s) {
        int c = s[u] - 'a';
        int old = last[c];

        if (last[c] != -1) {
            parent[u] = last[c];
        }

        last[c] = u;

        for (int v : adj[u]) {
            dfs1(v, parent, s);
        }

        last[c] = old;
    }

    int dfs2(int u) {
        int sz = 1;

        for (int v : tree[u]) {
            sz += dfs2(v);
        }

        answer[u] = sz;
        return sz;
    }

    std::vector<int> findSubtreeSizes(std::vector<int>& parent, std::string s) {
        int n = parent.size();

        adj.resize(n);
        tree.resize(n);
        answer.resize(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        dfs1(0, parent, s);
        for (int i = 1; i < n; i++) {
            tree[parent[i]].push_back(i);
        }

        dfs2(0);
        return answer;
    }
};
