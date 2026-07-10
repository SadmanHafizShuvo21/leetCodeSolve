class Solution {
public:
    const int LOG = 18;
    
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> ord;
        for (int i = 0; i < n; i++) {
            ord.push_back({nums[i], i});
        }
        sort(ord.begin(), ord.end());
        
        vector<int> val(n), pos(n);
        for (int i = 0; i < n; i++) {
            val[i] = ord[i].first;
            pos[ord[i].second] = i;
        }

        vector<int> comp(n);
        int id = 0;
        comp[0] = 0;
        for (int i = 1; i < n; i++) {
            if (val[i] - val[i - 1] > maxDiff) {
                id++;
            }
            comp[i] = id;
        }

        vector<int> nxt(n);
        int r = 0;
        for (int i = 0; i < n; i++) {
            while (r + 1 < n && val[r + 1] - val[i] <= maxDiff) {
                r++;
            }
            nxt[i] = r;
        }

        vector<vector<int>> up(LOG, vector<int>(n));
        for (int i = 0; i < n; i++) {
            up[0][i] = nxt[i];
        }

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        vector<int> ans;
        for (auto &q : queries) {
            int u = q[0];
            int v = q[1];

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            int a = pos[u], b = pos[v];
            if (a > b) {
                swap(a, b);
            }

            if (comp[a] != comp[b]) {
                ans.push_back(-1);
                continue;
            }

            int cur = a, dist = 0;
            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < b) {
                    dist += (1 << k);
                    cur = up[k][cur];
                }
            }

            ans.push_back(dist + 1);
        }

        return ans;
    }
};