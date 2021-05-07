// 给定一个二叉树，返回其节点值的锯齿形层序遍历。

// （即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>> ret;
      if(!root) return ret;
      queue<TreeNode*> nodeQueue;
      nodeQueue.push(root);
      bool isOrderLeft = true;
      while (!nodeQueue.empty()){
        // 
        deque<int> levelList;
        int size = nodeQueue.size();
        for(int i = 0; i != size; ++i){
          auto node = nodeQueue.front();
          nodeQueue.pop();
          if (isOrderLeft){
            levelList.push_back(node->val);
          }else{
            levelList.push_front(node->val);
          }
          if (node->left){
            nodeQueue.push(node->left);
          }
          if (node->right){
            nodeQueue.push(node->right);
          }
        }
        ret.emplace_back(vector<int> {levelList.begin(), levelList.end()});
        isOrderLeft = !isOrderLeft;
      }
      return ret;
    }
};