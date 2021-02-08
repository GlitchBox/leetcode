public class Solution {
    
    public bool isAlphanumeric(char c){
        
        if((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9') )
            return true;
        return false;
    }
    
    public bool isEqual(char c1, char c2){
        
        if(c1>='A' && c1<='Z')
            c1 = Convert.ToChar(c1 +('a'-'A'));
        if(c2>='A' && c2<='Z')
            c2 = Convert.ToChar(c2 + ('a'-'A'));
        
        if(c1==c2)
            return true;
        return false;
    }
    
    public bool IsPalindrome(string s) {
        
        int sLen = s.Length;
        
        
        if(sLen == 0)
            return true;
        
        int left = 0, right = sLen - 1;
        while(left<right){
            
            if(!isAlphanumeric(s[left]))
                left++;
            else if(!isAlphanumeric(s[right]))
                right--;
            else if(isEqual(s[left], s[right])){
                left++;
                right--;
            }
            else
                return false;
        }
        
        return true;
    }
}