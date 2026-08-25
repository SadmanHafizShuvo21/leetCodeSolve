class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }

        int x = k;
        while (s.count(x)) {
            x += k;
        }

        return x;
    }
};