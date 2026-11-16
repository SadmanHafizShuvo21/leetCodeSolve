
class Solution {
public:
    using ll = long long;

    ll digitSum(std::string s) {
        ll sum = 0;
        for (auto x : s) {
            sum += x - '0';
        }

        return sum;
    }

    std::vector<std::string> splitString(std::string s, int k) {
        std::vector<std::string> str;

        for (int i = 0; i < s.size(); i += k) {
            str.push_back(s.substr(i, k));
        }

        return str;
    }

    std::string calculateSum(std::vector<std::string>& str) {
        for (int i = 0; i < str.size(); i++) {
            ll x = digitSum(str[i]);
            str[i] = std::to_string(x);
        }

        std::string ans;
        for (auto x : str) {
            ans += x;
        }

        return ans;
    }

    std::string digitSum(std::string s, int k) {
        while (s.size() > k) {
            std::vector<std::string> str = splitString(s, k);
            s = calculateSum(str);
        }

        return s;
    }
};
