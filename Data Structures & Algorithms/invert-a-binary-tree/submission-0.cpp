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

    //     1
    //    / \
    //   2   3
    //  / \ / \
    // 4  5 6  7

    //root = 1
    TreeNode* invertTree(TreeNode* root) {
        //how we get out
        if(!root){
            return root;
        }
        //swap left and right
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        root->left = right;
        root->right = left;
        //call the swapping on left and right
        invertTree(left);
        invertTree(right);
        return root;
    }
};
