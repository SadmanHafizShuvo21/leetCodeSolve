class Solution {
public:
    using ll = long long;
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        ll ans = 0, n = img1.size();

        for (int x = -(n - 1); x < n; x++) {
            for (int y = -(n - 1); y < n; y++) {
                ll cnt = 0;

                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        int a = i + x;
                        int b = j + y;

                        if (a >= 0 && a < n && b >= 0 && b < n) {
                            if (img1[i][j] == 1 && img2[a][b] == 1) {
                                cnt++;
                            }
                        }
                    }
                }

                ans = std::max(ans, cnt);
            }
        }

        return ans;
    }
};