//naive solution using hashtable
public class Solution {
    public int MajorityElement(int[] nums) {
        
        int numsLen = nums.Length;
        Hashtable hashtable = new Hashtable();
        int major = numsLen/2;
        
        foreach(int i in nums){
            
            
            if(hashtable.ContainsKey(i))
                hashtable[i] = Convert.ToInt32(hashtable[i]) + 1;
            else
                hashtable[i] = 1;
        }
        
        int ret = -1;
        foreach(dynamic entry in hashtable){
            
            if(entry.Value>major){
                ret = entry.Key;
                break;
            }
                
        }
        
        return ret;
    }
}

//sorting, O(nlogn), O(1) space
public class Solution {
    public int MajorityElement(int[] nums) {
        
        int numsLen = nums.Length;
        Array.Sort(nums);
        //after the array is sorted
        //the majority element will be at numsLen/2th position
        return nums[numsLen/2];
    }
}

//boyer Moore voting algorithm
//a running sum will be kept
//it's a way of assigning +1 to major elements and -1 to non-major elements
//the major element is responsible for keeping the running sum greater than 0
public class Solution {
    public int MajorityElement(int[] nums) {
        
        //Boyer-Moore Voting algorithm
        int numsLen = nums.Length;
        int count = 1, major = nums[0];
        
        for(int i=1;i<numsLen;i++){
           
            if(major == nums[i])
                count++;
            else if(count==0){
                count++;
                major = nums[i];
            }
            else
                count--;
        }
        
        return major;
        
    }
}