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
    ListNode* deleteDuplicates(ListNode* head) {
           if(head == NULL || head->next == NULL)return head;
           ListNode* dummynode = new ListNode(-1);
           ListNode* temp = head;
           dummynode->next = head;
           ListNode* prev = dummynode;
           while(temp != NULL && temp->next != NULL){
            if(temp->val == temp->next->val){
                while(temp->next != nullptr && temp->val == temp->next->val){
                    temp = temp->next;
                }
                prev->next = temp->next;
            }
            else{
                prev = prev->next;
            }
            temp = temp->next;
           }
           return dummynode->next;
    }
};