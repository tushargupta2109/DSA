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
    
void GetsubtreeNodes(TreeNode* root, int k, vector<int>&ans){
    if(root == NULL || k<0){
        return;
    }
    if(k == 0){
        ans.push_back(root->val);
        return;
    }
    
    GetsubtreeNodes(root->left, k-1, ans);
    GetsubtreeNodes(root->right, k-1, ans);
}


int nodesAtDistK(TreeNode* root, TreeNode* target, int k, vector<int>&ans){
    
    if(root == NULL){
        return -1;
    }
    
    if(root == target){
        GetsubtreeNodes(root, k,ans);
        return 0;
    }
    
    int ld = nodesAtDistK(root->left, target, k, ans);
    
    if(ld != -1){
        if(ld + 1 == k){
            ans.push_back(root->val);
            
        }
        else{
            GetsubtreeNodes(root->right, k-ld-2, ans);
        }
        
        return ld+1;
    }
    
    int rd = nodesAtDistK(root->right, target, k, ans);
    
    if(rd != -1){
        if(rd + 1 == k){
            ans.push_back(root->val);
            
        }
        else{
            GetsubtreeNodes(root->left, k-rd-2, ans);
        }
        
        return rd+1;
    }
    
    return -1;
}
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    
        vector<int>ans;
        nodesAtDistK(root, target, k, ans);

        return ans;
    }
};