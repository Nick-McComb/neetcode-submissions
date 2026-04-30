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
    int maxDepth(TreeNode* root){
        if(!root){
            return 0;
        }
        int left = maxDepth(root->left) +1;
        int right = maxDepth(root->right) +1;
        return max(left,right);
    }

    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
      
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        int both = abs(left-right); //needs to be 0 or 1, lowkey dont know a good way to check
        bool even = both == 0 || both == 1;
        return even && isBalanced(root->left) && isBalanced(root->right);

    }
};
