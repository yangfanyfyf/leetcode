// 给定一个二叉树，返回它的 后序 遍历。

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
      if (!root) return {};
      vector<int> ret;
      stack<TreeNode*> stk;
      TreeNode *curr = root;
      TreeNode *prev = nullptr;
      while (!stk.empty() || curr){
        // 遍历一遍左子树
        while(curr){
          stk.push(curr);
          curr = curr->left;
        }
        // 返回上一个节点，叶子节点
        curr = stk.top();
        stk.pop();
        // 如果这个节点没有右节点，或者这个节点的右节点已访问过？但是
        if (curr->right == nullptr || curr->right == prev){
          ret.emplace_back(curr->val);
          prev = curr;
          curr = nullptr;
        }else{
          // 有右节点，则再次入栈，移动到下一个右节点
          stk.emplace(curr);
          curr = curr->right;
        }
      }
      return ret;
    }
};