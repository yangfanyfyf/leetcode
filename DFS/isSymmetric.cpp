// 给定一个二叉树，检查它是否是镜像对称的。

class Solution {
public:
    bool check(TreeNode *p, TreeNode *q){
      if (!q && !p) return true;
      if (!q || !p) return false;
      return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
      return check(root->left, root->right);
    }
};