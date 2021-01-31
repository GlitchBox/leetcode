
//extra memory solution
public class Solution {
    public void Rotate(int[] nums, int k) {
        
        int len = nums.Length;
        int[] ret = new int[len];
        for(int i=0;i<k;i++)
            ret[i] = nums[len-k+i];
        for(int i=k;i<len;i++)
            ret[i] = nums[i-k];
        
        for(int i=0;i<len;i++)
            nums[i] = ret[i];
    }
}