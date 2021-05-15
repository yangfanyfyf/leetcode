// 翻转一棵二叉树。

// 深度优先搜索
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
      if (!root) return nullptr;
      stack<TreeNode*> stk;
      // 压入栈
      stk.push(root);
      while(!stk.empty()){
        int size = stk.size();
        for (int i = 0; i != size; ++i){
          TreeNode *curr = stk.top();
          stk.pop();
          // 翻转
          TreeNode *temp = curr->left;
          curr->left = curr->right;
          curr->right = temp;
          // 这个顺序不重要吧？总是处理子树
          if (curr->right) stk.push(curr->right);
          if (curr->left) stk.push(curr->left);
        }
      }
      return root;
    }
};

// 递归
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
      if (!root) return nullptr;
      TreeNode *left = invertTree(root->left);
      TreeNode *right = invertTree(root->right);
      root->left = right;
      root->right = left;
      return root;
    }
};