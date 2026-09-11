class Solution {
public:
    using ll = long long;
    int totalNumbers(vector<int>& dig) {
        vector<int> freq(10, 0);
        for (int d : dig) {
            freq[d]++;
        }
        
        unordered_set<int> s;
        for (int i = 0; i <= 9; i += 2) {
            if (freq[i] == 0) {
                continue;
            }
            freq[i]--;
            
            for (int j = 1; j <= 9; j++) {
                if (freq[j] == 0) {
                    continue;
                }
                freq[j]--;
                
                for (int k = 0; k <= 9; k++) {
                    if (freq[k] == 0) {
                        continue;
                    }
                    s.insert(j * 100 + k * 10 + i);
                }
                
                freq[j]++;
            }
            
            freq[i]++;
        }
        
        return s.size();
    }
};