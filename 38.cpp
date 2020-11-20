class Solution {
public:
    string countAndSay(int n) {
     
        if(n == 1)
            return "1";
        
        string retBelow = countAndSay(n-1);
        
        int strLen = retBelow.length();
        int index = 0;
        
        string ret = "";
        char currentChar = retBelow[0];
        int count = 0;
        
        while(index<strLen){
            
            if(retBelow[index] == currentChar){
                count++;
                index++;
            }
            else{
                
                ret += string(1, count+'0');
                ret += string(1, currentChar);
                currentChar = retBelow[index]; 
                count = 0;
            }

        }
        ret += string(1, count+'0');
        ret += string(1, currentChar);
        
        // cout<<n<<", "<<ret<<endl;
        return ret;
    }
};