class Solution {
public:
    vector<string> createGrid(int m, int n) {
        std::vector<std::string> s(m);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == n - 1) {
                    s[i].push_back('.');
                }
                else {
                    s[i].push_back('#');
                }
            }
        }

        return s;
    }
};