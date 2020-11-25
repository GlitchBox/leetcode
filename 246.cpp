class Solution {
public:
    bool isStrobogrammatic(string num) {
        
        int numLen = num.length();
        int left = 0, right = numLen - 1;
        
        while(left<=right){
            
            if(left==right){
                if(num[left] != '1' && num[left] != '8' && num[left]!='0' )
                    return false;
            }
            else{
                if(num[left]==num[right]){
                    
                    if(num[left] != '1'  && num[left]!='8' && num[left]!='0')
                        return false;
                }
                else if( !(num[left]=='6' && num[right]=='9') && !(num[left]=='9' && num[right]=='6') )
                    return false;
            }
            right--;
            left++;
        }
        
        return true;
    }
};