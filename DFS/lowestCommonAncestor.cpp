// 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

// 深度优先搜索
class Solution {
public:
    TreeNode *ans;
    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q){
      // 自底向上更新
      if (!root) return false;
      bool lson = dfs(root->left, p, q);
      bool rson = dfs(root->right, p, q);
      // 判断条件
      if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))){
        ans = root;
      }
      return lson || rson || (root->val == p->val || root->val == q->val);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      dfs(root, p, q);
      return ans;
    }
};