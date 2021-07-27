import java.math.*;
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

//Approach: Store the values of the two listNodes in two stringbuilders. reverse them, then place the contents of the two builds into two big integers
//Add the two big ints together and then build out a listnode and return it

class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        StringBuilder string1 = new StringBuilder();                               //initialize Build1
        StringBuilder string2 = new StringBuilder();                               //initialize build2
        while(l1 != null)                                                          //while the list node isn't null
        {                                                                          //
            string1.append(Integer.toString(l1.val));                              //add the value to the build
            l1 = l1.next;                                                          //move up the node
        }                                                                          //
        while(l2 != null)                                                          //while the node isn't null
        {                                                                          //
            string2.append(Integer.toString(l2.val));                              //append the value to the build 
            l2 = l2.next;                                                          //move up the node
        }                                                                          //
        BigInteger num1 = new BigInteger(string1.reverse().toString());            //reverse the contents of the build and store it in a big int
        BigInteger num2 = new BigInteger(string2.reverse().toString());            //reverse the contents of the build and store it in a big int
        num1 = num1.add(num2);                                                     //add the two big ints together
        string1 = new StringBuilder(num1.toString());                              //store the added number to the build
        string1.reverse();                                                         //reverse it
        ListNode ret = new ListNode(Character.getNumericValue(string1.charAt(0))); //initialize a listnode to be returned
        ListNode head = ret;                                                       //save the starting point
        for(int i = 1; i < string1.length(); i++)                                  //iterate through our build
        {                                                                          //
            ret.next = new ListNode(Character.getNumericValue(string1.charAt(i))); //initialize the next node with the value in the string
            ret = ret.next;                                                        //move to the next node
        }                                                                          //
        return head;                                                               //return our starting point
    }                                                                              //space Complexity: O(4(n+m)) two list nodes, two big ints, two string builds,
                                                                                   //A list Node to return
}                                                                                  //Time Complexity: O(4(N+M)) store them to Builds, Reverse to big ints, reverse
                                                                                   //again, and then iterate through to create the list node
