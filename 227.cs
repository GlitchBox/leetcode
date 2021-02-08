public class Solution {
    
    public int StrToInt(string s){
        
        int sLen = s.Length;
        int ret = 0, power = 1;
        
        for(int i=sLen-1;i>-1;i--){
            
            ret += (power*(s[i]-'0'));
            power *= 10;
        }
        
        return ret;
    }
    
    public string getNumber(string s, int idx){
        
        int sLen = s.Length;
        int b = idx;
        
        while(idx<sLen){
            if(s[idx]>='0' && s[idx]<='9')
                idx++;
            else
                break;
        }
        
        return s.Substring(b, idx-b);
    }
    
    public int Calculate(string s) {
        
        Stack st = new Stack();
        int sLen = s.Length;
        int idx = 0;
        
        while(idx<sLen){
            
            //keep moving until all the spaces have been removed
            if(s[idx]==' ')
                idx++;
            
            //if a number has been found
            else if(s[idx]>='0' && s[idx]<='9'){
                string newNum = getNumber(s, idx);
                idx += newNum.Length;
                st.Push(StrToInt(newNum));
            }
            //if an operator has been found
            else{
                
                if(s[idx] == '+'){
                    st.Push(s[idx]);
                    idx++;
                }
                else{
                    // a multiplication or division operator has been found
                    //find the next number
                    char op = s[idx];
                    idx++;
                    
                    //keep moving until all the spaces have been removed
                    while(s[idx] == ' ')
                        idx++;
                    
                    string nextNum = getNumber(s, idx);
                    idx += nextNum.Length;
                    
                    if(op == '-'){
                        st.Push('+');
                        st.Push(-1*StrToInt(nextNum));
                    }
                    else{
                        //get the prevNumber
                        int prevNumber = Convert.ToInt32(st.Peek());
                        st.Pop();

                        if(op=='*')
                            st.Push(prevNumber*StrToInt(nextNum));
                        else
                            st.Push(prevNumber/StrToInt(nextNum));   
                        }
                }
            }
        }
        
        //now that all the multiplication and division is out of the way
        // I keep popping three things at once (two numbers and one operator)
        
        while(st.Count>1){
            
            int num2 = Convert.ToInt32(st.Peek());
            st.Pop();
            char op = Convert.ToChar(st.Peek());
            st.Pop();
            int num1 = Convert.ToInt32(st.Peek());
            st.Pop();
            
            if(op=='+')
                st.Push(num1+num2);
            else
                st.Push(num1-num2);
        }
        
        return Convert.ToInt32(st.Peek());
    }
}