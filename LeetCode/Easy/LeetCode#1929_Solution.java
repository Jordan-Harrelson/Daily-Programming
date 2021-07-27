import java.util.*;

class Solution {
    public int[] getConcatenation(int[] nums) {
        int[] returnArr = Arrays.copyOf(nums,nums.length*2);            //copy nums once into a new array
        System.arraycopy(nums, 0, returnArr, nums.length, nums.length); //copy it again into the new array
        return returnArr;                                               //return the new array
    }                                                                   //space: O(3N): original Array and the new array that is double the size of the original 
}                                                                       //Time: O(2N): Time to copy the original and copy it again