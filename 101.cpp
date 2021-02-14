/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/* 
    Recursive Theory:
    A tree is symmetric if the left and right subtrees are mirror images of each other 
                        If->    1) the left root and the right root have the same value
                                2) left subtree of one root is the mirror image of the right subtree of the other root
                                3) and vice versa  
*/
class Solution {
public:
    
    bool ifMirror(TreeNode* root1, TreeNode *root2){
        
        if(!root1 && !root2) 
            return true;
        if(!root1 || !root2)
            return false;
        
        return (root1->val == root2->val) && ifMirror(root1->left, root2->right) &&
            ifMirror(root1->right, root2->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        
        if(!root)
            return true;
        
        
        return ifMirror(root->left, root->right);
    }
};

/*
    Iterative theory:
    Using a queue, kinda like bfs traversal. The difference is, two nodes will be enqueued at a time.
    Logic is the same as the recursive one
*/


class Solution {
public:
    
    bool isSymmetric(TreeNode* root) {
        
        if(!root)
            return true;
        
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        
        while(!q.empty()){ 
            
            TreeNode* node1 = q.front();
            q.pop();
            TreeNode* node2 = q.front();
            q.pop();
            
            if((!node1 && node2) || (node1 && !node2))
                return false;
            else if(node1 && node2){
                
                if(node1->val != node2->val)
                    return false;
                
                q.push(node1->left);
                q.push(node2->right);
                
                q.push(node1->right);
                q.push(node2->left);
            }
        }
        
        
        return true;
        
    }
};