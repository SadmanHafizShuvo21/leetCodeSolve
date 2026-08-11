class Solution {
public:
    using ll = long long;

    int missingInteger(vector<int>& nums) {
        ll sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            }
            else {
                break;
            }
        }

        ll ans = sum;
        unordered_set<int> s(nums.begin(), nums.end());
        while(s.count(ans)) {
            ans++;
        }

        return ans;
    }
};