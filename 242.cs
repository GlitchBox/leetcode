public class Solution {
    public bool IsAnagram(string s, string t) {
        
        char[] sArray = s.ToCharArray();
        char[] tArray = t.ToCharArray();
        
        Array.Sort(sArray);
        Array.Sort(tArray);
        
        if(sArray.Length != tArray.Length)
            return false;
        
        for(int i=0;i<tArray.Length;i++){
            if(tArray[i] != sArray[i])
                return false;
        }
        
        return true;
    }
}

public class Solution {
    public bool IsAnagram(string s, string t) {
        
        int[] characters = new int[26];
        
        for(int i=0;i<s.Length;i++)
            characters[s[i] - 'a']++;
        for(int i=0;i<t.Length;i++)
            characters[t[i]-'a']--;
        
        for(int i=0;i<26;i++){
            if(characters[i]!=0)
                return false;
        }
        
        return true;
    }
}