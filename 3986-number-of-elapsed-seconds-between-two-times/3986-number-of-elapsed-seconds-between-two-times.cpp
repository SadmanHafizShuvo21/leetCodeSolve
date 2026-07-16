class Solution {
public:
    int time(string s) {
        int h = stoi(s.substr(0, 2));
        int m = stoi(s.substr(3, 2));
        int sec = stoi(s.substr(6, 2));

        return h * 60 * 60 + m * 60 + sec;
    }
    int secondsBetweenTimes(string startTime, string endTime) {
        int r = time(endTime);
        int l = time(startTime);

        return r - l;
    }
};