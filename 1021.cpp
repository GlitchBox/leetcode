class Solution {
public:
    string removeOuterParentheses(string S) {
        
        string ret = "";
        int sLen = S.length();
        
        int startIndex = 0, endIndex = 0;
        int open = 0, closed = 0;
        
        for(int i=0;i<sLen;i++){
            if(S[i] == '(' ){
                open++;
            }
            else{
                closed++;
            }
            if(open && open==closed){
                ret = ret + S.substr(startIndex+1, endIndex-startIndex-1);
                startIndex = i+1;
                endIndex = i+1;
                open = 0;
                closed = 0;
            }
            else{
                endIndex++;
            }
        }
        
        return ret;
    }
};