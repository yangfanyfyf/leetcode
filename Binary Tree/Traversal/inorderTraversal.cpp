// 给定一个二叉树的根节点 root ，返回它的 中序 遍历。

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
      if (!root) return {};
      vector<int> ret;
      stack<TreeNode*> stk;
      TreeNode *curr = root;
      while (!stk.empty() || curr){
        while(curr){
          // 访问完所有的左子树
          stk.push(curr);
          curr = curr->left;
        }
        // 回到叶子节点
        curr = stk.top();
        stk.pop();
        ret.push_back(curr->val);
        curr = curr->right;
      }
      return ret;
    }
};