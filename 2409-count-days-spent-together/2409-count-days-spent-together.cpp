class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        auto convert = [&](string s) {
            int m = stoi(s.substr(0, 2));
            int d = stoi(s.substr(3, 2));

            for (int i = 0; i < m - 1; i++) {
                d += days[i];
            }

            return d;
        };

        int a = max(convert(arriveAlice), convert(arriveBob));
        int b = min(convert(leaveAlice), convert(leaveBob));

        return max(0, b - a + 1);
    }
};