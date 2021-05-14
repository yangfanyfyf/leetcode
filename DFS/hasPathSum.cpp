// 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum ，判断该树中是否存在 根节点到叶子节点 的路径，

// 这条路径上所有节点值相加等于目标和 targetSum 。

// 作者：力扣 (LeetCode)
// 链接：https://leetcode-cn.com/leetbook/read/dfs/e8gh3h/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// 深度优先搜索
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
      if (!root) return false;
      if (!root->left && !root->right) return targetSum == root->val;
      return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};



// 如何记录遍历的每一条轨迹？
// 广度优先搜索
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
      if (root == nullptr){
        return false;
      }
      // 使用queue保存所有可能的节点
      queue<TreeNode*> que_node;
      queue<int> que_val;
      // 压入根节点
      que_node.push(root);
      que_val.push(root->val);
      while (!que_node.empty()){
        // 处理当前节点
        TreeNode *curr = que_node.front();
        int temp = que_val.front();
        que_node.pop();
        que_val.pop();
        if (curr->left == nullptr && curr->right == nullptr){
          if (temp == targetSum){
            return true;
          }
          continue;
        }
        if (curr->left != nullptr){
          que_node.push(curr->left);
          que_val.push(curr->left->val + temp);
        }
        if (curr->right != nullptr){
          que_node.push(curr->right);
          que_val.push(curr->right->val + temp);
        }
      }
      return false;
    }
};