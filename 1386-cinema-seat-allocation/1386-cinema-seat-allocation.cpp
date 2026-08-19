class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& res) {
        vector<pair<int, int>> pr;
        
        int nn = res.size();
        for (int i = 0; i < nn; i++) {
            pr.push_back({res[i][0], res[i][1]});
        }

        sort(pr.begin(), pr.end());

        long long ans = 2LL * n;
        int i = 0;

        while (i < pr.size()) {
            int row = pr[i].first;

            bool l = true, mid = true, r = true;

            int j = i;
            while (j < pr.size() && pr[j].first == row) {
                int seat = pr[j].second;

                if (seat >= 2 && seat <= 5)
                    l = false;

                if (seat >= 4 && seat <= 7)
                    mid = false;

                if (seat >= 6 && seat <= 9)
                    r = false;

                j++;
            }

            int grp = 0;
            if (l && r) {
                grp = 2;
            }
            else if (l || mid || r) {
                grp = 1;
            }

            ans -= 2;
            ans += grp;

            i = j;
        }

        return ans;
    }
};