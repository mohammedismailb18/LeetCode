* [Discussion Link](https://leetcode.com/problems/sum-of-left-leaves/discuss/1558155/c-simple-solution-two-recursive-method-1-iterative) 

**Recursive Solution**
```
int sumOfLeftLeaves(TreeNode* root) {
     if(!root)
         return 0;
     if(root->left && !root->left->left && !root->left->right)
         return root->left->val + sumOfLeftLeaves(root->right);
     return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}
```
----------------------------------------------------------------------
**Recursive Solution using left position**
```
int sumOfLeftLeaves(TreeNode* root, bool leftPos = false) {
     if(!root)
         return 0;
     if(leftPos && !root->left && !root->right)
         return root->val;
     return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
}
```
----------------------------------------------------------------------
**Iterative Solution**
```
int sumOfLeftLeaves(TreeNode* root) {
     stack<TreeNode*> s;
     s.push(root);
     int sum = 0;
     while(!s.empty()){
         root = s.top(); s.pop();
         if(root->left && !root->left->left && !root->left->right)
             sum += root->left->val;
         if(root->left)
             s.push(root->left);
         if(root->right)
             s.push(root->right);
     }
     return sum;
}
```
----------------------------------------------------------------------
* **Time Complexity = O(N)** where N is the no of nodes in the binary tree
* **Space Complexity = O(H)** where H is the maximum height of binary tree which can go upto O(N) in case of a skew binary tree.

**IF YOU FIND IT HELPFUL, PLEASE SHOW SOME SUPPORT IN THE FORM OF UPVOTE**