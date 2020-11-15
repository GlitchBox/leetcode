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

//Fast DFS solution
class Solution {
public:
    vector<int> retVal;
    void recurse(TreeNode* root, int depth){
        
        if(!root)
            return;
        
        if(depth <= retVal.size())
            retVal[depth-1] = max(root->val, retVal[depth-1]);
        else
            retVal.push_back(root->val);
        
        recurse(root->left, depth+1);
        recurse(root->right, depth+1);

    }
    
    vector<int> largestValues(TreeNode* root) {
    
        if(!root)
            return retVal;
        recurse(root, 1);
        
        return retVal;
    }
};

//even faster BFS solution
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> retVal;
        if(!root)
            return retVal;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int maxVal;
        while(!q.empty()){
            
            int nodesInCurrentDepth = q.size();
            maxVal = INT_MIN;
            
            for(int i=0;i<nodesInCurrentDepth;i++){
                
                TreeNode *curr = q.front();
                q.pop();
                maxVal = max(maxVal, curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            retVal.push_back(maxVal);
        }
        
        return retVal;
    }
};