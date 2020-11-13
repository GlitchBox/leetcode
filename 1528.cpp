class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        
        int len = s.length();
        int idx = 0;
        while(idx<len){
            
            if(indices[idx] != idx){
                int c = s[indices[idx]];
                s[indices[idx]] = s[idx];
                s[idx] = c;
                
                int changedIdx = indices[indices[idx]];
                indices[indices[idx]] = indices[idx];
                if(idx != changedIdx)
                    indices[idx] = changedIdx;
                else
                    idx++;
            }
            else
                idx++;

        }
        return s;
    }
};