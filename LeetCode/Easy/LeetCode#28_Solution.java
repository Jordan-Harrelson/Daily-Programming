class Solution {
    public int strStr(String haystack, String needle) {
        if(needle.equals(haystack))                                     //if both strings are equal to each other
            return 0;                                                   //return 0
        for(int i = 0; i < (haystack.length()-needle.length()+1); i++)  //run a loop ending just before the length of our needle
        {                                                               //
            if(haystack.substring(i,i+needle.length()).equals(needle))  //if we've found a substring match
                return i;                                               //return first index
        }                                                               //
        return -1;                                                      //else return 0
    }                                                                   //Space: O(1)
}                                                                       //Time: O(n)