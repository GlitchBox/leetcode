/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        
        TreeNode* ret = NULL;
        
        //go one right and then all left, as long as you can go
        if(p->right){
            root = p->right;
            while(root){
                ret = root;
                root = root->left;
            }
        }
        else{
            
            //if the right subtree doesn't exist, the successor is somewhere on the way from root to the node
            while(root!=p){
            
                // cout<<root->val<<endl;
                if(root->val<p->val)
                    root = root->right;
                else{
                    if(ret){
                        if(ret->val > root->val)
                            ret = root;
                    }
                    else
                        ret = root;
                    root = root->left;

                }
            }
        }
        
        return ret;
        
    }
};