class Solution {
public:
    using ll = long long;
    int findGCD(vector<int>& nums) {
        ll mn = *std::min_element(nums.begin(), nums.end());
        ll mx = *std::max_element(nums.begin(), nums.end());
        
        return std::__gcd(mn, mx);
    }
};