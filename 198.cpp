class Solution {
public:
    int dp[110][110];
    
    //two states:  house index, houses robbed
    int recursion(int index, int robbed, vector<int>& nums){
        
        if(index>=nums.size())
            return 0;
        
        if(dp[index][robbed]!=-1)
            return dp[index][robbed];
        
        //take the current house
        int ret1 = nums[index] + recursion(index+2, robbed+1, nums);
        
        //don't take this one
        int ret2 = recursion(index+1, robbed, nums);
        
        return dp[index][robbed] = max(ret1, ret2);
    }
    
    int rob(vector<int>& nums) {
        
        memset(dp, -1, sizeof(dp));
        return recursion(0, 0, nums);
    }
};