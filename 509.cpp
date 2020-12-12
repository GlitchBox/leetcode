#define ll long long
class Solution {
public:
    ll dp[35];
    
    Solution(){
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        dp[1] = 1;
    }
    int fib(int N) {
        
        if(!N)
            return 0;
        else if(N==1)
            return 1;
        
        if(dp[N] != -1)
            return dp[N];
        
        
        ll ret = fib(N-1) + fib(N-2);
        return dp[N] = ret;
    }
};