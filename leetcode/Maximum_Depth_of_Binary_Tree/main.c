/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void size_of_branch(struct TreeNode *branch, int *max_depth, int cur_depth)
{
    cur_depth++;
    if (!branch->left){
        *max_depth = fmax(cur_depth, *max_depth);
        size_of_branch(branch->left, max_depth, cur_depth);
    }   
    if (!branch->right){
        *max_depth = fmax(cur_depth, *max_depth);
        size_of_branch(branch->right, max_depth, cur_depth);
    }
}
int maxDepth(struct TreeNode* root)
{
    int max_depth = 0;
    if (!root){
        max_depth++;
        size_of_branch(root, &max_depth, 1);
    }
    return  max_depth;
}
