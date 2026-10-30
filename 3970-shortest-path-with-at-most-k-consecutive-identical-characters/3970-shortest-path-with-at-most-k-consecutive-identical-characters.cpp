class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        const long long inf = 1e18;

        vector<vector<long long>> dist(n, vector<long long>(k + 1, inf));

        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, cnt] = pq.top();
            pq.pop();

            if (d != dist[u][cnt]) {
                continue;
            }

            if (u == n - 1) {
                return d;
            }

            for (auto [v, w] : adj[u]) {
                int nc = (labels[u] == labels[v]) ? cnt + 1 : 1;

                if (nc > k) {
                    continue;
                }

                if (d + w < dist[v][nc]) {
                    dist[v][nc] = d + w;
                    pq.push({d + w, v, nc});
                }
            }
        }

        return -1;
    }
};