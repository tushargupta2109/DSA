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
class Solution {
public:
    
    int getHeight(TreeNode* root){
        
        if(root == NULL){
            return 0;
        }
        
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
    
    int deepestSum(TreeNode* root, int height){
        
        height = height - 1;
        
        if(root == NULL){
            return 0;
        }
        
        if(height == 0){
            
            return root->val;
        }
        
        return deepestSum(root->left, height) + deepestSum(root->right, height);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        
        int height = getHeight(root);
        
        return deepestSum(root, height);
    }
};