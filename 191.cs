public class Solution {
    public int HammingWeight(uint n) {
        
        int ones = 0;
        while(n>0){
            ones += Convert.ToInt32(n&1);
            n>>=1;
        }
        
        return ones;
    }
}