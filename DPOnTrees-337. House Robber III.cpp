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
      int  ans;
     unordered_map<TreeNode *,int>dp;
    
    int solve(TreeNode *root){
        
        if(!root) return 0;
        if(dp.count(root)){
            return dp[root];
        }
        
         int include_root=root->val;
        if(root  and root->left){
          include_root+=solve(root->left->left)+solve(root->left->right);   
        }   
        if(root and root->right){
            
             include_root+=solve(root->right->left)+solve(root->right->right);
        }
     
        int exclude_root=solve(root->left)+solve(root->right);
        
        ans=max(include_root,exclude_root);
        
        
        
        return dp[root]=ans;
        
        
    }
    int rob(TreeNode* root) {
      
        ans=0;
        solve(root);
        
        return ans;
    }
};
