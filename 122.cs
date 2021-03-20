public class Solution {
    public int MaxProfit(int[] prices) {
        
        int profit = 0;
        
        int b=0,e=0;
        for(int idx=1;idx<prices.Length;idx++){
            
            if(prices[e]>prices[idx]){
                profit += (prices[e] - prices[b]);
                b = idx;
                e = idx;
            }
            else
                e++;
        }
        if(prices[b]<prices[e])
            profit += (prices[e]-prices[b]);
        
        return profit;
    }
}