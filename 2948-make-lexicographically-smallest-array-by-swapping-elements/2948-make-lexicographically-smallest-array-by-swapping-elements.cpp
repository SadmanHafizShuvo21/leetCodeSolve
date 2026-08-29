class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& a, int l) {
        int n = a.size();

        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({a[i], i});
        }

        sort(v.begin(), v.end());

        int i = 0;

        while (i < n) {
            int j = i;

            while (j + 1 < n &&
                   (long long)v[j + 1].first - v[j].first <= l) {
                j++;
            }

            vector<int> p;

            for (int k = i; k <= j; k++) {
                p.push_back(v[k].second);
            }

            sort(p.begin(), p.end());

            for (int k = 0; k < p.size(); k++) {
                a[p[k]] = v[i + k].first;
            }

            i = j + 1;
        }

        return a;
    }
};