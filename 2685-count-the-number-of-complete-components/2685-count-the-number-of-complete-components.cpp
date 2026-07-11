class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis;

    void dfs(int u, int &nodes, int &degSum) {
        vis[u] = true;
        nodes++;
        degSum += adj[u].size();

        for (int v : adj[u]) {
            if (!vis[v]) {
                dfs(v, nodes, degSum);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        vis.assign(n, 0);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int nodes = 0, degSum = 0;
                dfs(i, nodes, degSum);

                int edgeCnt = degSum / 2;
                int need = nodes * (nodes - 1) / 2;
                if (edgeCnt == need) {
                    ans++;
                }
            }
        }

        return ans;
    }
};