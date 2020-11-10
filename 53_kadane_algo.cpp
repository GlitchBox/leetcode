class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        //kadane's algorithm
        int maxSum = -2147483647;
        int runningSum = 0;
        int numLen = nums.size();
        
        for(int i=0;i<numLen;i++){
            
            //if the runningSum becomes larger if I add ith number to it, I add it to the runningSum, thus we continue with the current subarray
            //if the ith number itself becomes larger than the runningSum(withAdd), we keep track of a new subarrayarray starting from the ith index
            runningSum = runningSum + nums[i];
            if(runningSum<nums[i])
                runningSum = nums[i];
            if(runningSum>maxSum)
                maxSum = runningSum;

        }
        
        return maxSum;
        
    }
};