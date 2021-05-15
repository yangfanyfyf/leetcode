// 给你一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。
// 每条从根节点到叶节点的路径都代表一个数字：

// 例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
// 计算从根节点到叶节点生成的 所有数字之和 。

// 叶节点 是指没有子节点的节点。

// 作者：力扣 (LeetCode)
// 链接：https://leetcode-cn.com/leetbook/read/dfs/e84677/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


class Solution {
public:
    int dfs(TreeNode *root, int preSum){
      if (!root) return 0;
      int sum = preSum * 10 + root->val;
      if (!root->left && !root->right){
        return sum;
      }else {
        return dfs(root->left, sum) + dfs(root->right, sum);
      }
    }
    int sumNumbers(TreeNode* root) {
      return dfs(root, 0);
    }
};