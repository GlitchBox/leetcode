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
        
        if(!head)
            return head;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(curr){
        
            if(curr->next && curr->next->val == curr->val){
                ListNode *nextCurr = curr->next;
                while(nextCurr && nextCurr->val == curr->val){
                    nextCurr = nextCurr->next;
                }
                if(prev)
                    prev->next = nextCurr;
                curr = nextCurr;
            }
            else{
                if(!prev)
                    head = curr;
                prev = curr;
                curr = curr->next;
            }
        }
        if(!prev)
            return prev;
        
        return head;
    }
};