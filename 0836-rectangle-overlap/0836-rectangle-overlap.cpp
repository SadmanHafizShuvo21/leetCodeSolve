class Solution {
public:
    using ll = long long;

    bool chk(ll x, ll y, ll a, ll b) {
        return (std::min(x, a) - std::max(y, b)) > 0;
    }
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        bool ok1 = chk(rec1[3], rec1[1], rec2[3], rec2[1]);
        bool ok2 = chk(rec1[2], rec1[0], rec2[2], rec2[0]);

        return ok1 & ok2;
    }
};