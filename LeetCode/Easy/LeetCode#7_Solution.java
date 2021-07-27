class Solution {
    public int reverse(int x) {
        boolean negative =  (x < 0) ? true : false;                //determine if our number is negative and set it the boolean accordingly                   
        StringBuilder num = new StringBuilder(Integer.toString(x));//create a stringbuilder to store the number to reverse as a string
        num.reverse();                                             //reverse it
        if(negative)                                               //is it negative? 
            num.insert(0,"-");                                     //add a minus to the front
        if(num.charAt(num.length()-1) == '-')                      //if it there is a minus symbol at the end
            num.deleteCharAt(num.length()-1);                      //remove it
        long num2 = Long.parseLong(num.toString());                //turn the string into a long
        if(num2 > Math.pow(2,31)-1 || num2 < Math.pow(-2,31))      //if the int exceeds the size of an int
            return 0;                                              //return 0
        return Integer.parseInt(num.toString());                   //return the string as an integer
    }                                                              //space complexity O(N) size of stringbuild
}                                                                  //time complexity O(N/2) time to reverse the string