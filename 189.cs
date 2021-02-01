
//extra memory solution
public class Solution {
    public void Rotate(int[] nums, int k) {
        
        int len = nums.Length;
        k %= len;

        if(len>1){
            int[] ret = new int[len];
            for(int i=0;i<k;i++)
                ret[i] = nums[len-k+i];
            for(int i=k;i<len;i++)
                ret[i] = nums[i-k];
            
            for(int i=0;i<len;i++)
                nums[i] = ret[i];
        }
    }
}


//in place, O(1) memory solution
public class Solution {
    
    public void printArra(int[] nums){
        
        foreach(int n in nums)
            Console.WriteLine(n);
    }
    
    public void reverse(int[] nums, int b, int e){
        
        int lim = (e-b+1)/2;
        for(int i=0;i<lim;i++){
            int temp = nums[i+b];
            nums[i+b] = nums[e-i];
            nums[e-i] = temp;
        }
    }
    
    public void Rotate(int[] nums, int k) {
        
        int len = nums.Length;
        k = k%len;
        if(len>1){
            reverse(nums,0, len-1);
            // printArra(nums);
            reverse(nums,0,k-1);
            // printArra(nums);
            reverse(nums,k,len-1);   
        }
        
    }
}