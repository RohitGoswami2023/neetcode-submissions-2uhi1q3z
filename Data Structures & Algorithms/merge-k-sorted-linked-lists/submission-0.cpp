class compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;   // Min Heap
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for (auto head : lists) {
            if (head)
                pq.push(head);
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {

            ListNode* curr = pq.top();
            pq.pop();

            tail->next = curr;
            tail = curr;

            if (curr->next)
                pq.push(curr->next);
        }

        return dummy.next;
    }
};