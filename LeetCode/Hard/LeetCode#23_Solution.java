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
    public ListNode mergeKLists(ListNode[] lists) {
        List<Integer> theList = new ArrayList<Integer>(); //create a list to store values
        if(lists.length == 0)                             //if the incoming list is empty
            return null;                                  //return null
        else if(lists.length == 1 && lists[0] == null)    //if there is one null item
            return null;                                  //return null
        for(int i = 0; i < lists.length; i++)             //run through the array
        {                                                 //
            while(lists[i] != null)                       //while the item we're looking at isn't null
            {                                             //
                theList.add(lists[i].val);                //add the value to our list
                lists[i] = lists[i].next;                 //iterate to the next item
            }                                             //
        }                                                 //
        Collections.sort(theList);                        //sort our list of values
        if(theList.size() == 0)                           //if we encountered nothing but nulls
            return null;                                  //return null
        ListNode head = new ListNode(theList.get(0));     //create a new listnode and add the first item
        ListNode start = head;                            //create a temp to store our starting point
        for(int i = 1; i < theList.size(); i++)           //run through our list
        {                                                 //
            head.next = new ListNode(theList.get(i));     //create a listnode and add it to the next position
            head = head.next;                             //move along 
        }                                                 //
        return start;                                     //return the beginning of the head
    }                                                     //Size: O(2N) ListNode and the List
}                                                         //runtime: O(N(array size) * M(ListNode size) * N * N) 