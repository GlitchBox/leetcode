/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public bool IsPalindrome(ListNode head) {
        
        List<int> values = new List<int>();
        
        ListNode ptr = head;
        while(ptr != null){
            
            values.Add(ptr.val);
            ptr = ptr.next;
        }
        
        for(int i=0;i<values.Count/2;i++){
            if(values[i] != values[values.Count-1-i])
                return false;
        }
        
        return true;
    }
}