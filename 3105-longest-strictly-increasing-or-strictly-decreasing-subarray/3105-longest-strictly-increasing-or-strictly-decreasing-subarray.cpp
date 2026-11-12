class Solution {
public:
    using ll = long long;

    ll chkf(std::vector<int> arr) {
        ll mx = 1, cnt = 1, fst = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > fst) {
                cnt++;
            }
            else {
                cnt = 1;
            }
            fst = arr[i];
            mx = std::max(mx, cnt);
        }

        return mx;
    }

    int longestMonotonicSubarray(vector<int>& nums) {
        ll cnt1 = chkf(nums);

        std::reverse(nums.begin(), nums.end());

        ll cnt2 = chkf(nums);

        return std::max(cnt1, cnt2);
    }
};