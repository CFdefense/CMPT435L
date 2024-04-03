/**
 * You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
 * Merge nums1 and nums2 into a single array sorted in non-decreasing order.
 * The final sorted array should not be returned by the function, but instead be stored inside the array nums1. 
 * To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, 
 * and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
 * 
 * 
 * ex: Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3 Output: [1,2,2,3,5,6]
 * ex: Input: nums1 = [1], m = 1, nums2 = [], n = 0 Output: [1]
*/
class MergeSorted {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        //k represents the end of the nums1 list
        int k = m + n -1;
        //i represents the number of values in the nums1 list that are not empty
        int i = m -1;
        //j represents the number of values in the nums2 list
        int j = n -1;
        //while we have more to look at in nums2
        while(j >= 0) {
            //determine if theres some to look at in nums1 and if its bigger or smaller than the one were looking at in nums2
            if(i>= 0 && nums1[i] > nums2[j]) {
                //add to end of nums1
                nums1[k] = nums1[i];
                //decrement
                k--;
                i--;
            }//if
            else {
                //add to end of nums1
                nums1[k] = nums2[j];  
                //decrement 
                k--;
                j--;
            }//else
        }//while
    }//merge
}//MergeSorted