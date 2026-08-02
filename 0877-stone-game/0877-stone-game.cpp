class Solution {
public:
    using ll = long long;
    bool stoneGame(vector<int>& piles) {
        ll n = piles.size();
        sort(piles.begin(), piles.end());
        
        if (piles[0] == piles[n - 1]) {
            return false;
        }
        
        return true;
    }
};