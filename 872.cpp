class Solution {
public:
    
    void returnLeaves(TreeNode* root, vector<int> &leaves){
        
        if(!root->left && !root->right){
            leaves.push_back(root->val);
            return;
        }
        
        if(root->right)
            returnLeaves(root->right, leaves);
        if(root->left)
            returnLeaves(root->left, leaves);
        
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
     
        vector<int> leaves1;
        vector<int> leaves2;
        returnLeaves(root1, leaves1);
        returnLeaves(root2, leaves2);
        
        if(leaves1.size()!=leaves2.size())
            return false;
        else{
            
            for(int i=0;i<leaves1.size();i++){
                if(leaves1[i] != leaves2[i])
                    return false;
            }
        }
        
        return true;
    }
};