class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int pos = 1, first = -1, last = -1, mn = INT_MAX;
        ListNode *prev = head, *cur = head->next;

        while (cur && cur->next) {
            int a = prev->val, b = cur->val, c = cur->next->val;

            if ((b > a && b > c) || (b < a && b < c)) {
                if (first == -1) {
                    first = pos;
                }
                else {
                    mn = min(mn, pos - last);
                }

                last = pos;
            }

            prev = cur;
            cur = cur->next;
            pos++;
        }

        if (first == -1 || first == last) {
            return {-1, -1};
        }

        return {mn, last - first};
    }
};