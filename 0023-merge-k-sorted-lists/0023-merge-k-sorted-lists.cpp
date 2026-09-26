class Solution {
public:
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) { 
            return a->val > b->val; 
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for (ListNode* head : lists) {
            if (head)
                pq.push(head);
        }
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            curr->next = node;
            curr = curr->next;

            if (node->next)
                pq.push(node->next);
        }

        return dummy.next;
    }
};