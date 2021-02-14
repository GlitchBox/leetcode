//used the iterative process instead of recursive one

class Solution {
public:
    void populateVector(int numRows, int idx, vector<vector<int>>&pascal){
        
        if(idx==numRows)
            return;
        
        while(idx<numRows){
            pascal[idx].push_back(1);
            for(int i=0;i<pascal[idx-1].size()-1;i++){
                pascal[idx].push_back(pascal[idx-1][i]+pascal[idx-1][i+1]);
            }
            pascal[idx].push_back(1);
            idx++;
        }
    }
    
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ret(numRows);
        if(!numRows)
            return ret;
        
        ret[0].push_back(1);
        populateVector(numRows, 1, ret);
        
        return ret;
    }
};