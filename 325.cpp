class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        
        int numLen = nums.size();
        if(!numLen)
            return 0;
        
        //I need to find an index j so that the condition : cumulativeSum - map[sumToFind] = k 
        //and map[sumToFind] = j holds
        //this means that the sum of the numbers in range (nums[j+1],nums[j+2],...,nums[i])
        //is equal to k
        // we may find an i, for which cumulativeSum = k, then cumulativeSum - k = 0
        //Since, we are trying to find the length of this subarray
        //the length will be i+1 in this case, this is exactly why I put map[0] = -1
        //if cumulativeSum-k==0, then i-map[0] = i-(-1) = i+1
        unordered_map<int,int> map;
        map[0] = -1;
        int maxLen = 0;
        int cumulativeSum = 0;
        
        for(int i=0;i<numLen;i++){
            
            cumulativeSum += nums[i];
            int sumToFind = cumulativeSum - k;
            if(map.find(sumToFind) != map.end())
                maxLen = max(maxLen, i - map[sumToFind]);
            if(map.find(cumulativeSum) == map.end())
                map[cumulativeSum] = i;
        }
        
        return maxLen;
    }
};