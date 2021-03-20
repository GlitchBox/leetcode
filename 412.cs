public class Solution {
    public string NumToStr(int n){
        
        string ret = "";
        
        if(n%3>0 && n%5>0){
            
            while(n>0){
                char c = (char)(n%10 + '0');
                ret += c.ToString();
                n /= 10;
            }
            
            char[] retArra = ret.ToCharArray();
            Array.Reverse(retArra);
            ret = new string(retArra);
            return ret;
        }
        if(n%3==0)
            ret += "Fizz";
        if(n%5==0)
            ret += "Buzz";
        
        return ret;
    }
    
    public IList<string> FizzBuzz(int n) {
     
        ArrayList ret = new ArrayList();
        
        for(int i=1;i<=n; i++){
            
            string s = NumToStr(i);
            ret.Add(s);
        }
        return ret.Cast<string>().ToList();
    }
}