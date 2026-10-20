#include <bits/stdc++.h>
using ll = long long;
using ld = double;
using lld = long double;
using llx = __int128;

const ll inf = 1e18;
const ll N = 1e5 + 5;
const ld error = 1e-6;
const lld pi = acosl(-1.0L);
const ll mod = 122333221;

class Solution {
public:
    int sortableIntegers(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> fac;

        for (int x = 1; x * x <= n; ++x) {
            if (n % x == 0) {
                fac.push_back(x);
                if (n / x != x) {
                    fac.push_back(n / x);
                }
            }
        }

        std::vector<int> target = nums;
        std::ranges::sort(target);

        auto kmp = [](const std::vector<int>& a, const std::vector<int>& b) {
            int n = a.size(), m = b.size();
            std::vector<int> pi(m, 0);
            int j = 0;

            for (int i = 1; i < m; ++i) {
                while (j > 0 && b[i] != b[j]) {
                    j = pi[j - 1];
                }
                if (b[i] == b[j]) {
                    ++j;
                }
                pi[i] = j;
            }

            j = 0;
            for (int i = 0; i < n; ++i) {
                while (j > 0 && a[i] != b[j]) {
                    j = pi[j - 1];
                }
                if (a[i] == b[j]) {
                    ++j;
                }
                if (j == m) {
                    return true;
                }
            }

            return false;
        };

        auto check = [&](const std::vector<int>& a, const std::vector<int>& b) {
            std::vector<int> doubled = a;
            doubled.insert(doubled.end(), a.begin(), a.end());
            return kmp(doubled, b);
        };

        int ans = 0;

        for (int d : fac) {
            bool ok = true;

            for (int l = 0; l < n; l += d) {
                int r = l + d - 1;

                std::vector<int> a(nums.begin() + l, nums.begin() + r + 1);
                std::vector<int> b(target.begin() + l, target.begin() + r + 1);

                if (!check(a, b)) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                ans += d;
            }
        }

        return ans;
    }
};