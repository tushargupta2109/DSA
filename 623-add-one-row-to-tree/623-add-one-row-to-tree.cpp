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
    
    void solve(TreeNode* root, int val, int depth){
        
        if(root == NULL || depth < 2){
            return;
        }
            
        if(depth == 2){
            
            TreeNode* leftTree = NULL, *rightTree = NULL;
            if(root->left){
                leftTree = root->left;
            }
            TreeNode* Node = new TreeNode(val);
            root->left = Node;
            Node->left = leftTree;
            
            if(root->right){
                rightTree = root->right;
            }
            TreeNode* NodeRight = new TreeNode(val);
            root->right = NodeRight;
            NodeRight->right = rightTree;
            return;
        }
        
        solve(root->left, val, depth - 1);
        solve(root->right, val, depth - 1);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth == 1){
            
            TreeNode* Node = new TreeNode(val);
            Node->left = root;
            return Node;
        }
        solve(root, val, depth);
        return root;
    }
};