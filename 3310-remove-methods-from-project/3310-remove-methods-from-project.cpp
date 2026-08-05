class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& adj) {
        std::vector<vector<int>> arr(n);
        for (auto &e : adj) {
            arr[e[0]].push_back(e[1]);
        }

        std::vector<bool> vis(n, false);

        auto dfs = [&](auto self, int u) -> void {
            vis[u] = true;
            for (auto v : arr[u]) {
                if (!vis[v]) {
                    self(self, v);
                }
            }
        };

        dfs(dfs, k);

        for (auto &e : adj) {
            if (!vis[e[0]] && vis[e[1]]) {
                std::vector<int> ans(n);
                iota(ans.begin(), ans.end(), 0);

                return ans;
            }
        }

        std::vector<int> ans;
        for (int i = 0; i < n; i++) {
            if(!vis[i]) {
                ans.push_back(i);
            }
        } 

        return ans;
    }
};