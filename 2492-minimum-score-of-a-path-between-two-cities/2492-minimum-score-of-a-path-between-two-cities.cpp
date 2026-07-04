class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> arr(n + 1);
        for (auto x : roads) {
            int u = x[0], v = x[1], w = x[2];
            arr[u].push_back({v, w});
            arr[v].push_back({u, w});
        }

        int ans = 1e9;
        queue<int> pq;
        vector<bool> vis(n + 1, false);

        pq.push(1);
        vis[1] = true;
        while(!pq.empty()) {
            int u = pq.front();
            pq.pop();  

            for (auto &[v, w] : arr[u]) {
                ans = min(ans, w);
                if (!vis[v]) {
                    vis[v] = true;
                    pq.push(v);
                }
            }
        }
        return ans;
    }
};