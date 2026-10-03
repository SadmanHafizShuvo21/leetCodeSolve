class Solution {
public:
    using ll = long long;
    int longestValidParentheses(string s) {
        std::stack<ll> st;
        st.push(-1);

        ll ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } 
            else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } 
                else {
                    ans = std::max(ans, i - st.top());
                }
            }
        }

        return ans;
    }
};