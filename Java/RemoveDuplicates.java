/*
 * Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. 
 * The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
 * Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
 * Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. 
 * The remaining elements of nums are not important as well as the size of nums.
 * Return k. WIP
 */
class RemoveDuplicates {
    public int removeDuplicates(int[] nums) {
        //Hashmap
        int k = 0;
        HashMap<Integer, Integer> numsHash = new HashMap<Integer, Integer>();
        
        for(int i = 0; i < nums.length ; i++)
        {
            if((numsHash.containsKey(nums[i])) == false)  {
                numsHash.put(i,nums[i]);
                    k++;
            }
        }
        int index = 0;
        for (int value : numsHash.values()) {
            nums[index++] = value;
        }//for
        return k;
    }//removeDuplicates
}//Solution