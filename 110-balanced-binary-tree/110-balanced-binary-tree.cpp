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
    
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        int lh = height(root->left), rh = height(root->right);
        return max(lh, rh) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        
        if(root == NULL){
            return true;
        }
        
        if(!isBalanced(root->left)){
            return false;
        }
        
        if(!isBalanced(root->right)){
            return false;
        }
        
        int lheight = height(root->left);
        int rheight = height(root->right);
        
        if(abs(lheight - rheight) <= 1){
            return true;
        }    
        return false;
    }
};