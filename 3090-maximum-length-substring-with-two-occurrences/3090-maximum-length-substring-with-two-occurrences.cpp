class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> seen(26, 0);
        
        int ans = 0, j = 0;
        for (int i = 0; i < s.size(); i++) {
            seen[s[i] - 'a']++;

            while(seen[s[i] - 'a'] > 2) {
                seen[s[j] - 'a']--;
                j++;
            }

            ans = std::max(ans, i - j + 1);
        }

        return ans;
    }
};