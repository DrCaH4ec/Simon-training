/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define SWAP(x, y, type) {type buf = x; x = y; y = buf;}

struct TreeNode* invertTree(struct TreeNode* root){
    if (root){
        invertTree(root->left);
        invertTree(root->right);
        SWAP(root->right, root->left, struct TreeNode*);
    }
    return root;
}
