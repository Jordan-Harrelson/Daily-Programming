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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head.next == null)          //if there's only one node
            return null;               //return null
        int length = 1;                //set length of node list as 1
        int count = 1;                 //set count for later to 1
        ListNode start = head;         //create pointer for head of the listnode
        while(head.next != null)       //move through loop while head.next isn't null
        {                              //
            head = head.next;          //move to the next node
            length++;                  //increment our length
        }                              //
        head = start;                  //reset the head
        if(length-n == 0)              //if we are to remove the first element
            return head.next;          //do so
        while(count < length-n)        //move to the node we want to remove
        {                              //
            start = start.next;        //keep moving
            count++;                   //increment count
        }                              //
        start.next = start.next.next;  //remove the node we want removed    
        return head;                   //return the start
    }                                  //Space O(1)
}                                      //Time O(2n)