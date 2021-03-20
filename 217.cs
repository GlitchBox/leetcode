public class Solution {
    public bool ContainsDuplicate(int[] nums) {
        
        Hashtable map = new Hashtable();
        foreach(int n in nums){
            if(map.Contains(n))
                return true;
            else
                map[n] = 1;
        }
        
        return false;
    }
}