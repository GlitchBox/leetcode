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
class FindElements {
public:
    
    unordered_map<int, int> seen;
    FindElements(TreeNode* root) {
        recursiveFix(root, 0);
    }
    
    void recursiveFix(TreeNode* curr, int val){
        
        if(!curr)
            return;
        curr->val = val;
        seen[val] = 1;
        
        recursiveFix(curr->right, curr->val*2 + 2);
        recursiveFix(curr->left, curr->val*2 + 1);
    }
    
    bool find(int target) {
        
//         queue<TreeNode*> q;
//         q.push(treeRoot);
        
//         while(!q.empty()){
            
//             TreeNode* topNode = q.front();
//             q.pop();
            
//             if(topNode->val == target)
//                 return true;
//             if(topNode->right && topNode->right->val<=target)
//                 q.push(topNode->right);
//             if(topNode->left && topNode->left->val<=target)
//                 q.push(topNode->left);
//         }
        if(seen.find(target) != seen.end())
            return true;
        
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */