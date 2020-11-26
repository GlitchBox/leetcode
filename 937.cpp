class Solution {
public:
    static int findFirstSpace(string s){
        
        for(int i=0;i<s.length();i++){
            
            if(s[i]==' ')
                return i;
        }
        return -1;
    }
    
    static bool compareLetterLog(string log1, string log2){
       
       int logPart1 = findFirstSpace(log1);
        int logPart2 = findFirstSpace(log2);
        
        string id1 = log1.substr(0, logPart1);
        string logString1 = log1.substr(logPart1+1);
        
        string id2 = log2.substr(0, logPart2);
        string logString2 = log2.substr(logPart2+1);
        
        if(logString1==logString2)
            return id1<id2;
        return logString1<logString2;
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        
        vector<string> lett;
        vector<string> dig;
        
        for(int i=0;i<logs.size();i++){
            
            int space = findFirstSpace(logs[i]);
            if(logs[i][space+1] >= '0' && logs[i][space+1]<='9')
                dig.push_back(logs[i]);
            else
                lett.push_back(logs[i]);
        }
        
        sort(lett.begin(), lett.end(), compareLetterLog);
        for(int i=0;i<dig.size();i++)
            lett.push_back(dig[i]);
        
        return lett;
    }
};