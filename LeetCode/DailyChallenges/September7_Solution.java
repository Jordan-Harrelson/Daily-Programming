/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        if(head == null)                                //if head is null
            return head;                                //return head
        ListNode returnNode = new ListNode(head.val);   //create a new node with first node of the head
        head = head.next;                               //move head to next position
        while(head != null)                             //iterate while head doesn't equal null
        {                                               //
            ListNode tempNode = new ListNode(head.val); //create a tempNode with the next head node
            tempNode.next = returnNode;                 //set the return node to temps next
            returnNode = tempNode;                      //set return to tempnode
            head = head.next;                           //increment the head
        }                                               //
        return returnNode;                              //return the reversed head
    }
}
