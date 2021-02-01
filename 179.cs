public class Solution {
    
    public int comparator(String s1, String s2){
        
        String t1 = s1+s2;
        String t2 = s2+s1;
        
        return -t1.CompareTo(t2);
    }
    
    public String removeStartZero(String s){
        
        int startzero = 0;
        int sLen = s.Length;
        
        for(int i=0;i<sLen;i++){
            if(s[i] == '0')
                startzero++;
            else
                break;
        }
        
        if(startzero==sLen)
            return "0";
        return s.Substring(startzero);
    }
    
    public string LargestNumber(int[] nums) {
       
        int numsLen = nums.Length;
        String[] numsStrArra = new String[numsLen];
        
        for(int i=0;i<numsLen;i++)
            numsStrArra[i] = Convert.ToString(nums[i]);
        
        //reverse-lexicographic sorting
        Array.Sort<String>(numsStrArra, new Comparison<String>(comparator));
        
        // foreach(String s in numsStrArra)
        //     Console.WriteLine(s);
        String ret = "";
        foreach(String s in numsStrArra)
            ret += s;
        
        return removeStartZero(ret);
    }
}