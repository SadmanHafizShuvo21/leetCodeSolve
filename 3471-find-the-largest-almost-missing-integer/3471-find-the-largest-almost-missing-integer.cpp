class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cnt(51, 0);

        for (int i = 0; i + k <= n; i++) {
            set<int> st;

            for (int j = i; j < i + k; j++) {
                st.insert(nums[j]);
            }

            for (int x : st) {
                cnt[x]++;
            }
        }

        for (int x = 50; x >= 0; x--) {
            if (cnt[x] == 1) {
                return x;
            }
        }

        return -1;
    }
};