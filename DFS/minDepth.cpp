// 给定一个二叉树，找出其最小深度。


class Solution {
public:
    int minDepth(TreeNode* root) {
      if (root == nullptr){
        return 0;
      }
      if (root->left == nullptr && root->right == nullptr){
        return 1;
      }
      int minDep = INT_MAX;
      if (root->left != nullptr){
        minDep = min(minDepth(root->left), minDep);
      }
      if (root->right != nullptr){
        minDep = min(minDepth(root->right), minDep);
      }
      return minDep + 1;
    }
};