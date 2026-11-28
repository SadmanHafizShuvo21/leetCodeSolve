class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());

        for (int i = 1; i < arr.size() - 1; i++) {
            int dif = arr[i] - arr[i - 1], diff = arr[i + 1] - arr[i];
            if (dif != diff) {
                return false;
            }
        }

        return true;
    }
};