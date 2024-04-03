/*
 * Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. 
 * The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
 * Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
 * Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. 
 * The remaining elements of nums are not important as well as the size of nums.
 * Return k.
 */
class RemoveDuplicates {
    public int method(int[] nums) {
        //two pointers
        int curr = 0;
        int next = 0;
        boolean Break = false;
        int i = 0; //location array
        int k = 0; //num of unique elements
        
            while(i < nums.length) {
                curr = nums[next];
                nums[k] = curr;
                k++;
                next++;
                //find how many of curr
                while(Break == false && next<nums.length) {
                  if(nums[next] == curr) {
                      nums[next] = 0;
                       next++;
                    }//if
                    else {
                        Break = true;
                    }//else
                }//while
            i+=next;
            }//while
            return k;
        }//method
    }//RemoveDuplicates
