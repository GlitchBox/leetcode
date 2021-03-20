public class Solution {
    public void MoveZeroes(int[] nums) {
        
        //find the first zero
        int left = 0;
        while(left<nums.Length && nums[left] != 0){
            left++;
        }
        
        //we have found a zero
        if(left<nums.Length){
            int right = left + 1;
            
            while(right<nums.Length){
                
                if(nums[right] != 0){
                    int temp = nums[right];
                    nums[right]= nums[left];
                    nums[left] = temp;
                    left++;
                }
                right++;
            }
        }
    }
}