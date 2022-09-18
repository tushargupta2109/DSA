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
    
    int idx;
    int search(vector<int> inorder, int curr, int start, int end){
        
        for(int i=start;i<=end;i++){
            if(curr == inorder[i]){
                return i;
            }
        }
        return -1;
    }
    
    TreeNode* solve(vector<int> inorder, vector<int> postorder, int start, int end){
        
        if(start>end){
            return NULL;
        }
        
        int curr = postorder[idx--];
        TreeNode* node = new TreeNode(curr);
        
        if(start == end){
            return node;
        }
        
        int pos = search(inorder, curr, start, end);
        node->right = solve(inorder, postorder, pos+1, end);
        node->left = solve(inorder, postorder, start, pos-1);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        idx = inorder.size()-1;
        return solve(inorder, postorder, 0, inorder.size()-1);
    }
};