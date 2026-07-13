class Solution {
public:
    double const inf = 1e-9;
    int countKthRoots(int l, int r, int k) {
        int x = ceil(pow(l, 1.0 / k) - inf);;
        int y = floor(pow(r, 1.0 / k) + inf);
        return y - x + 1;
    }
};