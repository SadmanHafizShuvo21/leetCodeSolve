class Solution {
public:
    using ll = long long;
    vector<int> maxDepthAfterSplit(string seq) {
        std::vector<int> res;

        ll cnt = 0;
        for (auto x : seq) {
            if (x == '(') {
                cnt++;
                res.push_back(cnt % 2);
            } 
            else {
                res.push_back(cnt % 2);
                cnt--;
            }
        }

        return res;
    }
};