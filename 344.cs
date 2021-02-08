public class Solution {
    public void ReverseString(char[] s) {
        
        int sLen = s.Length;
        int lim = sLen/2;
        
        for(int i=0;i<lim;i++){
            char temp = s[i];
            s[i] = s[sLen-1-i];
            s[sLen-i-1] = temp;
        }
    }
}