class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int >map;
        //this is done so that the first time, the cumSum becomes k
        //we have sth to add to retCount
        map[0] = 1; 
        
        int cumSum = 0;
        int numLen = nums.size();
        int retCount = 0;
        for(int i=0;i<numLen;i++){
            
            cumSum += nums[i];
            int sumToFind = cumSum - k;
            
            if(map.find(sumToFind) != map.end()){
                retCount += map[sumToFind];
            }
            if(map.find(cumSum) == map.end() ){
                map[cumSum] = 1;
            }
            else
                map[cumSum] += 1;
        }
        
        return retCount;
    }
};