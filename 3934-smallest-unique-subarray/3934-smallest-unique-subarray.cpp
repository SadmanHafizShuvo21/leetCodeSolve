class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sa(n), r(n), nr(n);
        for (int i = 0; i < n; i++) {
            sa[i] = i;
            r[i] = nums[i];
        }

        for (int k = 1; k < n; k *= 2) {
            sort(sa.begin(), sa.end(), [&](int a, int b) {
                if (r[a] != r[b]) {
                    return r[a] < r[b];
                }

                int x = (a + k < n ? r[a + k] : -1);
                int y = (b + k < n ? r[b + k] : -1);

                return x < y;
            });

            nr[sa[0]] = 0;
            for (int i = 1; i < n; i++) {
                int a = sa[i - 1], b = sa[i];
                nr[b] = nr[a] + (r[a] != r[b] || (a + k < n ? r[a + k] : -1) != (b + k < n ? r[b + k] : -1));
            }

            r = nr;
            if (r[sa[n - 1]] == n - 1) {
                break;
            }
        }

        vector<int> pos(n), lcp(n);
        for (int i = 0; i < n; i++) {
            pos[sa[i]] = i;
        }
            
        int h = 0;
        for (int i = 0; i < n; i++) {
            int p = pos[i];

            if (p == 0) {
                continue;
            }

            int j = sa[p - 1];
            while (i + h < n && j + h < n && nums[i + h] == nums[j + h]) {
                h++;
            }
                

            lcp[p] = h;
            if (h) {
                h--;
            }
        }

        int ans = n;
        for (int i = 0; i < n; i++) {
            int p = pos[i];
            int mx = lcp[p];
            if (p + 1 < n) {
                mx = max(mx, lcp[p + 1]);
            }
        
            if (mx < n - i) {
                ans = min(ans, mx + 1);
            } 
        }

        return ans;
    }
};