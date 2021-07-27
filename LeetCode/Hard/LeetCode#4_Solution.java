/*
*Approach: combine the two lists together, sort them and then return median of that list
*/
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        List<Integer> theList = new ArrayList();                    //create a list to store the two arrays
        for(int i : nums1)                                          //add all the ints in array 1 to the list
        {                                                           //
            theList.add(i);                                         //
        }                                                           //
        for(int i : nums2)                                          //add all the ints in array 2 to the list
        {                                                           //
            theList.add(i);                                         //
        }                                                           //
        Collections.sort(theList);                                  //sort the list
        if(theList.size() < 2)                                      //if there is only one element
            return theList.get(0);                                  //return that element
        if(theList.size()%2 == 0)                                   //if there are an even number of items
        {                                                           //
            double num1 = theList.get(theList.size()/2-1);          //get the int in the middle+1
            double num2 = theList.get(theList.size()/2 );           //get the int in the middle-1
            return (num1+num2)/2;                                   //return half of their sums
        }                                                           //
        return theList.get(theList.size()/2);                       //else return the middle number
    }                                                               //space complexity is O(2(m+n))
}                                                                   //time complexity is O(2(N+M))
