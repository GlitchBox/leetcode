class Solution {
public:
    
    int squareSum(int n){
        
        int ret = 0;
        while(n){
            
            int rem = n%10;
            ret += (rem*rem);
            n /= 10;
        }
        
        return ret;
    }
        
    bool isHappy(int n) {
        
        if(n==1)
            return true;
        
        unordered_map<int, int> visited;
        visited[n] = 1;
        
        while(1){
            n = squareSum(n);
            
            if(n==1)
                return true;
            
            if(visited.find(n) != visited.end())
                break;
            else
                visited[n] = 1;
        }
        
        return false;
    }
};