class Solution {
public:
    using ll = long long;

    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        std::sort(arr1.begin(), arr1.end());
        std::sort(arr2.begin(), arr2.end());

        ll ans = 0;
        for (int i = 0; i < arr1.size(); i++) {
            bool ok = true;
            for (int j = 0; j < arr2.size(); j++) {
                if (std::abs(arr1[i] - arr2[j]) <= d) {
                    ok = false;
                    break;
                }
            }

            ans += ok;
        }

        return ans;
    }
};