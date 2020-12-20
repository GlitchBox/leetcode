typedef struct TrieNode{
    
    TrieNode *child[26];
    bool isEndOfWord;
    
}TrieNode;

class Solution {
public:
    TrieNode* createNode(TrieNode* root, char key, bool isEndOfWord){
        
        TrieNode* newNode = new TrieNode;
        for(int i=0;i<26;i++)
            newNode->child[i] = NULL;
        newNode->isEndOfWord = isEndOfWord;
        
        root->child[key-'a'] = newNode;
        
        return newNode;
    }
    
    void populateTrie(vector<string>& words, TrieNode *root){
        
        for(int i=0;i<words.size();i++){
            TrieNode* cursor = root;
            for(int j=0;j<words[i].length();j++){
                
                char curr = words[i][j];
                if(cursor->child[curr-'a']){
                	if(j==words[i].length()-1)
                		cursor->child[curr-'a']->isEndOfWord = true;
                    cursor = cursor->child[curr-'a'];
                }
                else{
                    bool ifEnd = (j==words[i].length()-1)? true:false;
                    cursor = createNode(cursor, curr, ifEnd);
                }
            }
        }
    }
    
    void printAllWords(TrieNode* root){
        
        for(int i=0;i<26;i++){
            if(root->child[i]){
             printf("%c",i+'a');
             if(root->child[i]->isEndOfWord)
                 cout<<": eow"<<endl;
             cout<<endl;
             printAllWords(root->child[i]);
            }
        }
        
    }
    
    string largestWord(TrieNode* root, string curr){
        
        string ret = "";
        for(int i=0;i<26;i++){
            if(root->child[i] && root->child[i]->isEndOfWord){
                string temp = string(1, i+'a') + largestWord(root->child[i], string(1,i+'a'));
                if(temp.length()>ret.length()){
                    ret = temp;
                }
            }
        }
        
        return ret;
    }
    
    string longestWord(vector<string>& words) {
        
        TrieNode *root = new TrieNode;
        root->isEndOfWord = false;
        for(int i=0;i<26;i++)
            root->child[i] = NULL;
        
        populateTrie(words, root);

        return largestWord(root,"");
    }
};