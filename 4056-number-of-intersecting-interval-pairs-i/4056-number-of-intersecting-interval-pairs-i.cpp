class Solution {
public:
    using ll = long long;
    int countIntersectingIntervals(vector<vector<int>>& in) {
        std::vector<ll> st, ed;
        for (int i = 0; i < in.size(); i++) {
            st.push_back(in[i][0]);
            ed.push_back(in[i][1]);
        }

        std::sort(st.begin(), st.end());
        std::sort(ed.begin(), ed.end());
        
        ll ans = 0, j = 0, n = in.size();
        for (int i = 0; i < n; i++) {
            while (j < n && ed[j] < st[i]) {
                j++;
            }

            ans += i - j;
        }

        return ans;
    }
};