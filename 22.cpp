class Solution {
public:
    
    vector<string> result;
    void recursion(int opened, int closed, string interim, int n){
        
        // cout<<opened<<","<<closed<<endl;
        if(opened==closed && closed == n){
            result.push_back(interim);
            return;
        }
        
        //open a paren if possible
        if(opened<n){
            recursion(opened+1, closed,interim+"(", n);
        }
        
        //close a paren if possible
        if(closed<opened){
            recursion(opened, closed+1, interim+")",n);
        }
        return;
            
    }
    
    vector<string> generateParenthesis(int n) {
        
        recursion(0,0,"", n);
        return result;
    }
};