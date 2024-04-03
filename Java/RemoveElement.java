/**
 * Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. 
 * Then return the number of elements in nums which are not equal to val.
 * Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:
 * Change the array nums such that the first k elements of nums contain the elements which are not equal to val. 
 * The remaining elements of nums are not important as well as the size of nums.
 * Return k.
 */
class RemoveElement {
    public int removeElement(int[] nums, int val) {
        //number of elements not equal to val
        int k = 0;
        //check if not equal, then move to front and increment nums not equal to val
        for(int i = 0 ; i < nums.length ; i++) {
            if(nums[i] != val) {
                nums[k] = nums[i];
                    k++;
            }//if
        }//for
        //return number of nums not equal to val
        return k;
    }//removeElement
}//RemoveElement