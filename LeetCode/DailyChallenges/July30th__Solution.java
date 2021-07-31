class MapSum {                                                                                         //class declaration
    HashMap<String,Integer> theMap;                                                                    //declare a hashmap for the class
    /** Initialize your data structure here. */                                                        //
    public MapSum() {                                                                                  //defualt constructor
        theMap = new HashMap<String,Integer>();                                                        //initialize the hashmap 
    }                                                                                                  //
                                                                                                       //
    public void insert(String key, int val) {                                                          //Insert method to add a key val
        theMap.put(key,val);                                                                           //put the key val pair in the map, override if necessary
    }                                                                                                  //
                                                                                                       //
    public int sum(String prefix) {                                                                    //Sum method to add all strings that start with the prefix
        int sum = 0;                                                                                   //initialze a sum to return to 0
        for(String word : theMap.keySet())                                                             //iterate through the keys
        {                                                                                              //
            if(prefix.length() <= word.length() && word.substring(0,prefix.length()).equals(prefix))   //if the prefix is shorter than the key and the key starts with the prefix
                sum += theMap.get(word);                                                               //add the keys value to the sum
        }                                                                                              //
        return sum;                                                                                    //return the sum
    }                                                                                                  //Space: O(n) where N is the number of key/vals added
}                                                                                                      //Time: O(n) to iterate through all the key values

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */