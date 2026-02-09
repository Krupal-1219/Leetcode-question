class Solution {
public:
    Node* flatten(Node* head) {
        Node *p = head, *nxt;
        
        while(p){
            if(p->child){
                nxt = p -> next;
                p->next = flatten(p->child);
                p->child = NULL;
                p->next->prev = p;
                while(p->next){
                    p = p->next;    
                }
                p->next = nxt;
                if(nxt) nxt->prev = p;

            } else{
                p = p->next;
            }
        }
        
        return head;
    }
};