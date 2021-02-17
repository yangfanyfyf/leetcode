// 实现一个二叉搜索树迭代器。你将使用二叉搜索树的根节点初始化迭代器。

// 调用 next() 将返回二叉搜索树中的下一个最小的数。

// 中序遍历
class BSTIterator {
public:
    vector<TreeNode *> vec;
    int count;
    void traverse(TreeNode *root, vector<TreeNode *> &vec){
      if (root == nullptr) return;
      traverse(root->left, vec);
      vec.push_back(root);
      traverse(root->right, vec);
    }

    BSTIterator(TreeNode* root) {
      traverse(root, vec);
      count = 0;
    }
    
    // 返回下一个最小的数字
    // 如果left存在，继续访问left，否则返回当前值
    // 再去访问root的节点，之后访问right
    int next() {
      return vec[count++]->val;
    }
    
    // 是否存在其他没有被遍历到的节点
    bool hasNext() {
      return count != vec.size();
    }
};