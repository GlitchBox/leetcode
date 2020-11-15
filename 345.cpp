class Solution {
public:
    bool ifVowel(char c){
        if(c == 'a' || c=='e' || c=='i' || c=='o' || c=='u')
            return true;
        else if(c == 'A' || c=='E' || c=='I' || c=='O' || c=='U')
            return true;
        return false;
    }
    
    string reverseVowels(string s) {
        
        int sLen = s.length();
        int b = 0, e = sLen - 1;
        
        while(b<e){
            
            if(!ifVowel(s[b]) && ifVowel(s[e]))
                b++;
            else if(ifVowel(s[b]) && !ifVowel(s[e]))
                e--;
            else if( !(ifVowel(s[b]) && ifVowel(s[e])) ){
                b++;
                e--;
            }
            else{
                char temp = s[b];
                s[b] = s[e];
                s[e] = temp;
                b++;
                e--;
            }
            
        }
        
        return s;
    }

};