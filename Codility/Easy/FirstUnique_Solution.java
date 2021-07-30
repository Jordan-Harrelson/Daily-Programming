// you can also use imports, for example:
import java.util.*;

class Solution {
    public int solution(int[] A) {
        List<Integer> theList = new ArrayList<Integer>();   //create a list to store numbers we've come across
        for(int num : A)                                    //go through each num in the array
        {                                                   //
            if(theList.isEmpty())                           //if the list is empty
                theList.add(num);                           //add the element
            else if(!theList.remove(Integer.valueOf(num)))  //if the integer wasn't removed
                theList.add(num);                           //add it
        }                                                   //
        if(theList.size() == 0)                             //if the list is empty
            return -1;                                      //return -1
        return theList.get(0);                              //otherwise return the first element
    }                                                       //
}                                                           //
