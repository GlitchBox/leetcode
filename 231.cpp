//if an integer x in a power of 2, then it has only one bit that is 1, the rest of the bits are 0
// -x = ~x + 1
// (x &-x) == x, if x is a power of 2

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(!n)
            return false;
        
        long long x = n; //-(-2^31) won't fit in an integer
        if((x&-x) == x)
            return true;
        return false;
    }
};


//if n is a power of 2, (n&n-1) == 0
class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(!n)
            return false;
        
        long long x = n; //-2^31 - 1 can't fit in an integer

        if(x&(x-1))
            return false;
        return true;
    }
};