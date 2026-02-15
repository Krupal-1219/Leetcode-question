class Solution {
public:

    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;   // better split

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;

        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* mid = middleNode(head);
        ListNode* right = mid->next;
        mid->next = NULL;

        ListNode* left = sortList(head);
        right = sortList(right);

        return mergeTwoLists(left, right);
    }
};
