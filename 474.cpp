//for a better solution, i.e. for a 2d-dp solution check the solutions

class Solution {
public:
    
    int dp[610][110][110];
    
    int count(string s, char c){
        
        int ret = 0;
        for(int i=0;i<s.size();i++){
            if(c == s[i])
                ret++;
        }
        return ret;
    }
    
    int recursion(int idx, int zeros, int ones, int m, int n, vector<string>& str){
        
        if(zeros==m && ones==n)
            return dp[idx][zeros][ones] = 0;
        
        if(idx==str.size())
            return dp[idx][zeros][ones] = 0;
        
        if(dp[idx][zeros][ones] != -1)
            return dp[idx][zeros][ones];
        
        int ret1 = 0, ret2 = 0;
        //take the current string
        int zeroCount = count(str[idx], '0');
        int oneCount = count(str[idx], '1');
        
        if(zeroCount+zeros<=m && oneCount+ones<=n)
            ret1 = 1 + recursion(idx+1, zeros+zeroCount, ones+oneCount, m, n, str);
        //don't take this string
        ret2 = recursion(idx+1, zeros, ones, m, n, str);
        
        return dp[idx][zeros][ones] = max(ret1, ret2);
        
        
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        memset(dp, -1, sizeof(dp));
        return recursion(0,0,0,m,n, strs);
    }
};