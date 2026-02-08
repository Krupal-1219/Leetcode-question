/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* findthelastnode(ListNode* temp, int t){
        int cnt = 1;{
            while(temp != NULL){
                if (cnt == t)return temp;
                temp = temp->next;
                cnt++;
            }
        }
        return NULL;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)return head;
        ListNode* tail = head;
        int len = 1;
        while(tail->next != NULL){
            tail = tail->next;
            len += 1;
        }
        if (k%len == 0)return head;
        k = k%len;
        tail->next = head;

        ListNode* nextnode = findthelastnode(head,len-k);
        head = nextnode->next;
        nextnode->next = NULL;
        return head;

    }
};