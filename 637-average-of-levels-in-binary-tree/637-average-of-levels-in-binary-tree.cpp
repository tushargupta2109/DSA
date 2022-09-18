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
    vector<double> averageOfLevels(TreeNode* root) {
        
        queue<TreeNode*> q;
        vector<double> ans;
        q.push(root);
        q.push(NULL);
        vector<int> temp;
        
        while(!q.empty()){
            
            TreeNode* node = q.front();
            q.pop();
            
            if(node == NULL){
                
                int n = temp.size();
                double val = 0;
                for(int i=0;i<n;i++){
                    val += temp[i];
                }
                val = val/n;
                ans.push_back(val);
                temp.clear();
                
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                temp.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
        }
        return ans;
    }
};