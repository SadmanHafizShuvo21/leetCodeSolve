class Solution {
public:
    bool canAliceWin(int n) {
        int x = 10;
        while (n >= x) {
            n -= x;
            x--;
        }

        return x % 2 == 1;
    }
};