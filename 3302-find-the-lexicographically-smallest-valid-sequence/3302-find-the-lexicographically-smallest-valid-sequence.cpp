class Solution {
public:
    using ll = long long;

    vector<int> validSequence(string word1, string word2) {
        ll n = word1.size(), m = word2.size(), r = m - 1, cnt = 0;

        vector<ll> suf(n);
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = cnt;

            if(r >= 0 && word1[i] == word2[r]) {
                r--;
                cnt++;
            }
        }

        int j = 0;
        bool ok = false;
        vector<int> ans;
        for (int i = 0; i < n && j < m; i++) {
            if(word1[i] == word2[j]) {
                j++;
                ans.push_back(i);
            }

            else if(!ok && suf[i] >= m - 1 - j) {
                j++;
                ans.push_back(i);
                ok = true;
            }
        }

        if (j == m) {
            return ans;
        }

        return {};
    }
};