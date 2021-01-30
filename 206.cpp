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

//using extra memory
class Solution {
public:
    
    
    void recursion(ListNode* curr, queue<int> &q){
        
        if(!curr)
            return;
        
        q.push(curr->val);
        recursion(curr->next, q);
        curr->val = q.front();
        q.pop();
        
            
    }
    
    ListNode* reverseList(ListNode* head) {
        
        queue<int> q;
        recursion(head, q);
        return head;
    }
};

//without using extra memory
class Solution {
public:
    
    
    ListNode* reverseList(ListNode* head) {
        
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(curr){
            
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        return prev;
    }
};