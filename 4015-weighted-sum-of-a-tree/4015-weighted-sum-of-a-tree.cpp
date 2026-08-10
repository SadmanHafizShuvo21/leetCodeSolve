class Solution {
public:
    using ll = long long;

    int h = 0;
    vector<vector<int>> adj;
    vector<int> depth;
    void dfsHeight(int u, int d) {
        depth[u] = d;
        h = max(h, d);

        for (int v : adj[u]) {
            dfsHeight(v, d + 1);
        }
    }

    ll dfsWeight(int u, vector<int>& nums) {
        ll ans = 1LL * nums[u] * (h - depth[u] + 1);

        for (int v : adj[u]) {
            ans += dfsWeight(v, nums);
        }

        return ans;
    }

    ll weightedSum(vector<int>& p, vector<int>& nums) {
        int n = p.size();
        adj.assign(n, {});
        depth.assign(n, 0);
        for (int i = 1; i < n; i++) {
            adj[p[i]].push_back(i);
        }

        dfsHeight(0, 1);
        return dfsWeight(0, nums);
    }
};