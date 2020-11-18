class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int numLen = nums.size();
        if(!numLen)
            return 0;
        // while(numLen && nums[numLen-1] == val)
        //     numLen--;
        
        for(int i=0;i<numLen;i++){
            
            if(nums[i]==val){
                nums[i] = nums[numLen-1];
                numLen--;
                i--;
            }
        }
        return numLen;
    }
};