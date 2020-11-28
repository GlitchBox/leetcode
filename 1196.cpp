class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        
        unordered_map<string, int> map;
        stringstream ss;
        ss<<A<<" "<<B;
        string word;
        
        while(getline(ss, word, ' ')){
            map[word]++;
        }
        
        vector<string> ret;
        for(unordered_map<string, int>::iterator it = map.begin();it!=map.end();it++){
            if(it->second==1)
                ret.push_back(it->first);
        }
        
        return ret;
    }
};