class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};

        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return ans;

        int first = -1;
        int prev = -1;
        int minDist = INT_MAX;

        ListNode* prevNode = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;

        int index = 1;

        while (next != NULL) {
            if ((curr->val > prevNode->val && curr->val > next->val) ||
                (curr->val < prevNode->val && curr->val < next->val)) {

                if (first == -1) {
                    first = index;
                } else {
                    minDist = min(minDist, index - prev);
                }

                prev = index;
            }

            prevNode = curr;
            curr = next;
            next = next->next;
            index++;
        }

        if (first == -1 || prev == first)
            return ans;

        ans[0] = minDist;
        ans[1] = prev - first;

        return ans;
    }
};