class Solution {
public:
    using ll = long long;

    ll n, m;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool dfs(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= m) {
            return false;
        }

        if (grid[x][y] == 1) {
            return true;
        }

        grid[x][y] = 1;
        bool ok = true;

        for (int i = 0; i < 4; i++) {
            ok = dfs(grid, x + dx[i], y + dy[i]) && ok;
        }

        return ok;
    }

    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    if (dfs(grid, i, j)) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};