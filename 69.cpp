
#define ll long long
class Solution {
public:
    int mySqrt(int x) {
        
        if(!x)
            return x;
     
        ll l = 1, r = x, target = x;
        while(l<=r){
            
            ll mid = (l+r)/2;
            if(mid*mid>target)
                r = mid -1;
            else if(mid*mid == target)
                return mid;
            else
                l = mid + 1;
        }
        
        return r;
    }
};