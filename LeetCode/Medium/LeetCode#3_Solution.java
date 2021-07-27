class Solution {
    public int lengthOfLongestSubstring(String s) {
        if(s.length() == 0)                                                    //if the string is empty
            return 0;                                                          //return 0
        if(s.length() == 1)                                                    //if it's one
            return 1;                                                          //return 1
        int largest = 1;                                                       //set largest substring to return to 1
        HashMap<Character,Integer> theMap = new HashMap<Character,Integer>();  //create a hashmap to store characters and the number of occurences
                                                                               //this is faster than creating a list and using .contains() as maps 
                                                                               //have an O(1) return for retrievals. 
        for(int i = 0; i < s.length()-1; i++)                                  //iterate through substring
        {                                                                      //
            int j = i+1;                                                       //Set the end of the substring to i+1
            theMap.put(s.charAt(i),0);                                         //put the first element of our substring into the map
            while(!theMap.containsKey(s.charAt(j)))                            //while the map doesn't contain any of the chars we've encountered
            {                                                                  //
                theMap.put(s.charAt(j),0);                                     //place the next char into the map
                j++;                                                           //advance the end of the substring
                if(j >= s.length())                                            //if j is equal to the length of our substring
                    break;                                                     //break
            }                                                                  //
            if((j-i) > largest)                                                //if the length of our current substring is longer than our largest
                largest = j-i;                                                 //set it to largest
            theMap.clear();                                                    //clear our map
        }                                                                      //
        return largest;                                                        //return the largest substring
    }                                                                          //Space complexity O(N) Space of the Map
}                                                                              //Time Complexity O(N^2) 