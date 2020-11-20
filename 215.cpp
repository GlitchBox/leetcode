class Solution {
public:
    
    void swap(int idx1, int idx2, vector<int>& nums){
        
        if(idx1==idx2)
            return;
        nums[idx1] = nums[idx1] + nums[idx2];
        nums[idx2] = nums[idx1] - nums[idx2];
        nums[idx1] = nums[idx1] - nums[idx2];
    }
    
    //after running this algorithm, all the numbers smaller than pivot will be to the left of the partition
    // and all the values larger or equal than pivot will be on the right of the pivot
    int partition(int left, int right, int pivot_idx, vector<int>& nums){
        
        int pivot_val = nums[pivot_idx];
        //move pivot the very end
        swap(right, pivot_idx, nums);
        int correctPivotPos = left; //this will be the correct position of the pivot value after running this method
        
        for(int i=left; i<=right; i++){
            
            if(nums[i]<pivot_val){
                swap(i, correctPivotPos, nums);
                correctPivotPos++;
            }
        }
        
        //restore the pivot_val to its correct position
        swap(correctPivotPos, right, nums);
        return correctPivotPos;
    }
    
    //this method recursively calls itself to shrink the range between left and right
    //and tries to close in on the targetPos
    int quickselect(int left, int right, vector<int> & nums, int targetPos){
        
        if(left==right)
            return nums[left];

        int pivotPos = (left+right)/2;
        int correctPivotPos = partition(left, right, pivotPos, nums);
        
        if(correctPivotPos == targetPos)
            return nums[correctPivotPos];   
        else if(correctPivotPos>targetPos)
            return quickselect(left, correctPivotPos-1, nums, targetPos);
        return quickselect(correctPivotPos+1, right, nums, targetPos);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
     
        int numsLen = nums.size();
        return quickselect(0, numsLen-1, nums, numsLen-k);
    }
};