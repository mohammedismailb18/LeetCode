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
    
    int maxHeight(TreeNode* A){
        if(A == NULL)
            return -1;
        return 1 + max(maxHeight(A->left), maxHeight(A->right));
    }
    
    int deepestSum(TreeNode* A, int h){
        if(A == NULL)           //This path was not a deepest path in the tree
            return 0;
        else if(h == 0)         //If height reduced to zero => This is the deepest path
            return A->val;
        return deepestSum(A->left, h-1) + deepestSum(A->right, h-1);    //Just summing up the deepest node valuesfrom left  and right node
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int height = maxHeight(root);
        return deepestSum(root,height);
    }
};
