class Solution {
public:
    using ll = long long;
    bool checkOverlap(int r, int xC, int yC, int x1, int y1, int x2, int y2) {
        ll x = std::max(x1, std::min(xC, x2));
        ll y = std::max(y1, std::min(yC, y2));

        ll dx = x - xC;
        ll dy = y - yC;

        return dx * dx + dy * dy <= r * r;
    }
};