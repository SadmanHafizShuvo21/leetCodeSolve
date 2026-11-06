class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        std::sort(logs.begin(), logs.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });

        int m = queries.size();
        std::vector<std::pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            q.push_back({queries[i], i});
        }

        std::sort(q.begin(), q.end());
        
        std::vector<int> ans(m), cnt(n + 1, 0);
        int l = 0, r = 0, active = 0;

        for (auto [t, idx] : q) {
            while (r < logs.size() && logs[r][1] <= t) {
                int id = logs[r][0];
                if (cnt[id] == 0) {
                    active++;
                }

                cnt[id]++;
                r++;
            }

            while (l < r && logs[l][1] < t - x) {
                int id = logs[l][0];
                cnt[id]--;

                if (cnt[id] == 0) {
                    active--;
                }

                l++;
            }

            ans[idx] = n - active;
        }

        return ans;
    }
};