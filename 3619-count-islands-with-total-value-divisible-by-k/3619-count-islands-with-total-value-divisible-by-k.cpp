class Solution {
public:
    using ll = long long;

    ll n, m;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void dfs(vector<vector<int>>& grid, int x, int y, ll& sum) {
        if (x < 0 || x >= n || y < 0 || y >= m) {
            return;
        }

        if (grid[x][y] == 0 || grid[x][y] == -1) {
            return;
        }

        sum += grid[x][y];
        grid[x][y] = -1;

        for (int i = 0; i < 4; i++) {
            dfs(grid, x + dx[i], y + dy[i], sum);
        }
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size(), m = grid[0].size();

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    ll sum = 0;
                    dfs(grid, i, j, sum);

                    if (sum % k == 0) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};