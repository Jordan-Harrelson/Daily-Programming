// you can also use imports, for example:
import java.util.*;

//changed solution that resulted in 100%
//use map instead of list and iterate at worst case O(2N) 
//average time complexity O(N*log(N))
//space is O(N) for the hashmap

class Solution {
    public int solution(int[] A) {
        HashMap<Integer,Integer> theMap = new HashMap<Integer,Integer>(); //create a map to store ints and how many times they occur
        for(int num : A)                                                  //iterate through the array
        {                                                                 //
            if(theMap.containsKey(num))                                   //if the map contains the key
                theMap.put(num, theMap.get(num)+1);                       //update it +1
            else                                                          //otherwise
                theMap.put(num,1);                                        //put it in the map with 1 occurance
        }                                                                 //
        for(int num : A)                                                  //iterate through the list again
        {                                                                 //
            if(theMap.get(num) == 1)                                      //find an element with one occurance? 
                return num;                                               //return it
        }                                                                 //
        return -1;                                                        //return -1 one if no unique
    }
}