// For reference, check out solution (both dp and implementation solutions)

class Solution {
public:
    int longestValidParentheses(string s) {
        
        int left = 0, right = 0, maxLength = 0;
        
        for(int i=0;i<s.size();i++){
            
            if(s[i]=='(')
                left++;
            else
                right++;
            
            if(left==right)
                maxLength = max(maxLength, 2*right);
            else if(right>left){
                left = 0;
                right = 0;
            }
        }
        
        left = 0;
        right = 0;
        for(int i=s.size()-1;i>-1;i--){
            
            if(s[i]=='(')
                left++;
            else
                right++;
            
            if(left==right)
                maxLength = max(maxLength, 2*left);
            else if(right<left){
                left = 0;
                right = 0;
            }
        }
     
        return maxLength;
    }
};