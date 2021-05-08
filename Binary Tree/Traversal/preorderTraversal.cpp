// 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

// 根左右
// 使用栈，迭代实现
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
      if (!root) return {};
      // 存储返回值
      vector<int> ret;
      stack<TreeNode*> myStack;
      TreeNode *curr = root;
      while (!myStack.empty() || curr != nullptr){
        while(curr != nullptr){
          // 到达一个节点后，立刻输出这个节点的值
          ret.emplace_back(curr->val);
          // 压入根节点
          myStack.emplace(curr);
          // 访问左子树
          curr = curr->left;
        }
        // 返回根节点，开始访问右子树
        curr = myStack.top();
        myStack.pop();
        curr = curr->right;
      }
      return ret;
    }
};