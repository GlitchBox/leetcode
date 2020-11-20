class Solution {
public:
    int missingNumber(vector<int>& nums) {
     
        int numSize = nums.size();
        int expectedSum = (numSize*(numSize+1))/2;
        int sum = 0;
        
        for(int i=0;i<numSize;i++)
            sum += nums[i];
        
        return expectedSum - sum;
    }
};