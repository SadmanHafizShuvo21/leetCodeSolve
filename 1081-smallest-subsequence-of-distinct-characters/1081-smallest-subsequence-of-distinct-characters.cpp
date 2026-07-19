class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> cnt(26, 0);
        vector<bool> vis(26, false);

        for (auto x : s) {
            cnt[x - 'a']++;
        }

        string str;
        for (auto x : s) {
            cnt[x - 'a']--;
            if (vis[x - 'a']) {
                continue;
            }

            while(!str.empty() && str.back() > x && cnt[str.back() - 'a'] > 0) {
                vis[str.back() - 'a'] = false;
                str.pop_back();
            }

            str.push_back(x);
            vis[x - 'a'] = true;
        }
        
        return str;
    }
};