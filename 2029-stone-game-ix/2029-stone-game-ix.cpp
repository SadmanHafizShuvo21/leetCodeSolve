class Solution {
public:
    bool stoneGameIX(vector<int>& st) {
        std::vector<int> cnt(3, 0);

        for (auto x : st) {
            cnt[x % 3]++;
        }

        if (cnt[0] % 2 == 0) {
            return (std::min(cnt[1], cnt[2]) >= 1);
        }

        return std::abs(cnt[1] - cnt[2]) >= 3;
    }
};