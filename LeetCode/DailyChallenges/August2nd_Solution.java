class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> theMap = new HashMap<Integer, Integer>();          //create a map to store answers
        for(int i = 0; i < nums.length; i++)                                         //run through the array
        {                                                                            //
            theMap.put(nums[i],i);                                                   //add num and indice
        }                                                                            //
        for(int i = 0; i < nums.length; i++)                                         //run through again
        {                                                                            //
            if(theMap.containsKey(target-nums[i]) && i != theMap.get(target-nums[i]))//if the map contains the compliment of our target minus the current num and it's index isn't the one we're already on
            {                                                                        //
                int j = i;                                                           //set j to i
                i++;                                                                 //increment i
                while(nums[i] != target-nums[j])                                     //traverse till we find the complement
                {                                                                    //
                    i++;                                                             //increment i
                }                                                                    //
                return new int[]{j,i};                                               //return i and j as an array
            }                                                                        //
        }                                                                            //
        return new int[2];                                                           //else return null
    }                                                                                //Space O(n) for map
}                                                                                    //Time O(N+N) two traversals