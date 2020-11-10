class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* retHead = NULL;
        ListNode* curr = NULL;
        
        while(l1 || l2){
            
            ListNode* newNode = NULL;
            if(l1 && l2){
                
                if(l1->val <= l2->val){
                    newNode = new ListNode(l1->val);
                    l1 = l1->next;
                }
                else{
                    newNode = new ListNode(l2->val);
                    l2 = l2->next;
                }

            }
            else if(l1){
                
                newNode = new ListNode(l1->val);
                l1 = l1->next;
            }
            else{
                newNode = new ListNode(l2->val);
                l2 = l2->next;
            }
            
            if(curr){
                curr->next = newNode;
                curr = curr->next;
            }
            else{
                curr = newNode;
                retHead = newNode;
            }

        }
        
        return retHead;
    }
};