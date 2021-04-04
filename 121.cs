public class Solution {
    public int MaxProfit(int[] prices) {
        
        int largest = 0;
        int left=0, right = 0;
        
        while(right<prices.Length-1){
            
            if(prices[left]>prices[right+1]){
                right++;
                left = right;
            }
            else{
                right++;
                int temp = prices[right] - prices[left];
                largest = temp>largest?temp:largest;   

            }
        }
        
        return largest;
    }
}