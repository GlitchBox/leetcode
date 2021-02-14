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
//Theory: Since the array is sorted, I can use bisection. Each time, the middle element will be the root. 
//All the elements left to the middle element will belong to the left subtree
//All the elements right to the middle element will belong to the right subtree

class Solution {
public:
    TreeNode* recursion(int b, int e, vector<int>&nums){
        
        if(b>e)
            return NULL;
        if(b == e)
            return new TreeNode(nums[b]);
        
        int mid = (b+e)/2;
        TreeNode *root = new TreeNode(nums[mid], recursion(b,mid-1, nums), recursion(mid+1,e,nums));
        
        return root;
            
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        if(!nums.size())
            return NULL;
        
        return recursion(0, nums.size()-1, nums);
    }
};