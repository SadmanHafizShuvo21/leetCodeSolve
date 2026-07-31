class Solution {
public:
    using ll = long long;
    int minimumPushes(string word) {
        vector<int> cnt(26, 0);
        for (auto ch : word) {
            cnt[ch - 'a']++;
        }

        sort(cnt.rbegin(), cnt.rend());

        ll ans = 0;
        for (int i = 0; i < 26; i++) {
            ll m = 1 + i / 8;

            if (cnt[i] == 0) {
                break;
            }

            ans += (m * cnt[i]);
        }

        return ans;
    }
};