class Solution {
public:
    int digitCount(int n) {
        int cnt = 0;
        while (n > 0) {
            cnt++;
            n /= 10;
        }
        return cnt;
    }

    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        int l = digitCount(low), r = digitCount(high);

        vector<int> ans;
        for (int i = l; i <= r; i++) {
            for (int j = 0; i + j <= 9; j++) {
                string str = s.substr(j, i);
                
                int x = std::stoi(str);
                if (x >= low && x <= high) {
                    ans.push_back(x);
                }
            }
        }
        return ans;
    }
};