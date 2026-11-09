
class Solution {
public:
    using ll = long long;

    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> st;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        for (int i = 0; i < k; i++) {
            st.insert(i);
        }

        vector<int> cnt(k, 0);
        for (int i = 0; i < arrival.size(); i++) {
            ll t = arrival[i];

            while (!pq.empty() && pq.top().first <= t) {
                st.insert(pq.top().second);
                pq.pop();
            }

            if (st.empty()) {
                continue;
            }

            int id = i % k;
            auto it = st.lower_bound(id);

            if (it == st.end()) {
                it = st.begin();
            }

            int x = *it;
            st.erase(it);
            cnt[x]++;

            pq.push({t + load[i], x});
        }

        int mx = *max_element(cnt.begin(), cnt.end());

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            if (cnt[i] == mx) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
