class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        
        vector<string> ret;
        int stringNum = A.size();
        int charList[stringNum][26];
        memset(charList, 0, sizeof(charList));
        
        for(int i=0;i<stringNum;i++){
            for(int j=0;j<A[i].length();j++)
                charList[i][A[i][j]-'a']++;
        }
        
        for(int i=0;i<26;i++){
            int smallest = 110;
            for(int j=0;j<stringNum;j++)
                smallest = min(smallest, charList[j][i]);
            
            for(int j=0;j<smallest;j++)
                ret.push_back(string(1,i+'a'));
        }
        
        return ret;
    }
};