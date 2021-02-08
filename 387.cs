public class Solution {
    public int FirstUniqChar(string s) {
        
        Hashtable hashtable = new Hashtable();
        
        int sLen = s.Length;
        if(sLen==0)
            return -1;
        
        for(int i=0;i<sLen;i++){
            
            if(hashtable.ContainsKey(s[i])){
                hashtable[s[i]] = sLen;
            }
            else
                hashtable[s[i]] = i;
        }
        
        int ret = sLen;
        foreach(int val in hashtable.Values){
            if(val<ret)
                ret = val;
        }
        
        if(ret==sLen)
            return -1;
        
        return ret;
    }
}