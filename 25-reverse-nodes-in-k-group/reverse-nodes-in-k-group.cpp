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
    ListNode*findknode(ListNode*temp , int k){
        k-=1;
        while(temp!=NULL && k>0){
            k--;
            temp = temp->next;
        }return temp;
    }
public:
    ListNode* reverse(ListNode* head) {
        if(head==NULL || head->next ==NULL){
            return head;
        }
        ListNode*newhead = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newhead;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*temp = head;
        ListNode*prevnode = NULL;
        while(temp!=NULL){
            ListNode*knode = findknode(temp,k);
            if(knode==NULL){
                if(prevnode) prevnode->next = temp;
                break;
            }
            ListNode*nextnode = knode->next;
            knode->next = NULL;
            reverse(temp);
            if(temp==head){
                head = knode;
            }
            else{
                prevnode->next = knode;
            }
                prevnode = temp;
                temp = nextnode;
            
        }
        return head;
    }
};