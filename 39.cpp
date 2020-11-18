class Solution {
public:
    vector<vector<int>> returnList;
    vector<int> runningList;
    
    void recursion(int left, int index, vector<int>&candidates){
        
        if(!left){
            returnList.push_back(runningList);
            return;
        }
        if(index==candidates.size())
            return;
        
        //take the current index
        if(left-candidates[index]>-1){
            runningList.push_back(candidates[index]);
            recursion(left - candidates[index], index, candidates);
            runningList.pop_back();
        }
        else
            return;
        //don't take the current index
        recursion(left, index+1, candidates);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        recursion(target, 0, candidates);
        return returnList;
    }
};