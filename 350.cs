public class Solution {
    
    public void populateMap(int[] nums, Dictionary<int,int> dict){
        
        foreach(int num in nums){
            
            if(dict.ContainsKey(num) == true)
                dict[num] += 1; 
            else
                dict[num] = 1;
        }
    }
    
    public int[] Intersect(int[] nums1, int[] nums2) {
        
        
        Dictionary<int, int> dict1 = new Dictionary<int, int>();
        Dictionary<int, int> dict2 = new Dictionary<int, int>();
        Dictionary<int,int> final_dict = new Dictionary<int,int>();
        int size = 0;
        
        populateMap(nums1, dict1);
        populateMap(nums2, dict2);
        
        
        foreach(int key in dict1.Keys){
            if(dict2.ContainsKey(key)){
                size += Math.Min(dict1[key], dict2[key]);
                final_dict[key] = Math.Min(dict1[key], dict2[key]);
            }

        }
        
        // Console.Write(size);
        int[] ret = new int[size];
        int idx = 0;
        foreach(int key in final_dict.Keys){
            
            int times = final_dict[key];
            for(int i=0;i<times;i++,idx++)
                ret[idx] = key;

        }
        
        return ret;
        
    }
}