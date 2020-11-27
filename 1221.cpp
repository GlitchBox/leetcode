class Solution {
public:
    int balancedStringSplit(string s) {
     
        int sLen = s.length();
        int L = 0, R = 0;
        int subs = 0;
        
        for(int i=0;i<sLen;i++){
            
            if(s[i]=='R')
                R++;
            else if(s[i]=='L')
                L++;
            
            if(R==L){
                subs++;
                L=0;
                R=0;
            }
        }
        
        return subs;
    }
};