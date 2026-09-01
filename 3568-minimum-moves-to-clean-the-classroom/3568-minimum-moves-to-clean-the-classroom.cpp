class Solution {
public:
    int minMoves(vector<string>& a, int e) {
        int m = a.size(), n = a[0].size(), sx, sy;
        vector<pair<int,int>> l;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 'S') {
                    sx = i, sy = j;
                }
                if (a[i][j] == 'L') {
                    l.push_back({i, j});
                }
            }

        int k = l.size(), all = (1 << k) - 1;
        vector<vector<vector<int>>> d(m, vector<vector<int>>(n, vector<int>(1 << k, -1)));
        queue<array<int, 4>> q;
        q.push({sx, sy, 0, 0});
        d[sx][sy][0] = e;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        while (!q.empty()) {
            auto [x, y, mask, dis] = q.front();
            q.pop();

            if (mask == all) {
                return dis;
            }

            for (int z = 0; z < 4; z++) {
                int nx = x + dx[z], ny = y + dy[z];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n || a[nx][ny] == 'X') { 
                    continue;
                }

                int ne = d[x][y][mask] - 1;
                if (ne < 0) {
                    continue;
                }

                int nm = mask;
                for (int i = 0; i < k; i++) {
                    if (l[i] == make_pair(nx, ny)) {
                        nm |= 1 << i;
                    }
                }

                if (a[nx][ny] == 'R') {
                    ne = e;
                }

                if (d[nx][ny][nm] >= ne) {
                    continue;
                }

                d[nx][ny][nm] = ne;
                q.push({nx, ny, nm, dis + 1});
            }
        }

        return -1;
    }
};