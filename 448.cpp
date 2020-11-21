class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int>ret;
        int numsLen = nums.size();
        int i = 0;
        
        //marking it 0 means we have seen(or placed nums[i] at nums[nums[i]-1])
        for(int i=0;i<numsLen;i++){
            
            int seenIndex = abs(nums[i]) - 1;
            if(nums[seenIndex]>0){
                if(nums[seenIndex]>0)
                    nums[seenIndex] *= -1;
            }
        }
        
        for(i = 0;i<numsLen;i++){
            
            if(nums[i]>0)
                ret.push_back(i+1);
        }
        
        return ret;
    }
};


//my own solution
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int>ret;
        int numsLen = nums.size();
        int i = 0;
        
         while(i<numsLen){
            // cout<<i<<": "<<nums[i]<<", "<<nums[nums[i]-1]<<endl;
            if(nums[nums[i]-1] != nums[i]){
                
                int temp = nums[i];
                nums[i] = nums[temp-1];
                nums[temp-1] = temp;
            }
            else
                i++;
         }
        
        for(i = 0;i<numsLen;i++){
            
            if(nums[i] != i+1)
                ret.push_back(i+1);
        }
        
        return ret;
    }
};