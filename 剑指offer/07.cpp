// 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。

// 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

class Solution {
private:
    // 使用哈希表制造映射
    unordered_map<int, int> index;
public:
    TreeNode* myBuildTree(vector<int> &preorder, vector<int> &inorder, int preorderLeft, int preorderRight, int inorderLeft, int inorderRight){
        if (preorderLeft > preorderRight){
            return nullptr;
        }
        int preorderRoot = preorderLeft;
        int inorderRoot = index[preorder[preorderRoot]];
        // 建立根节点
        TreeNode *root = new TreeNode(preorder[preorderRoot]);
        // 得到左子树节点数目
        int sizeLeftSubtree = inorderRoot - inorderLeft;
        root->left = myBuildTree(preorder, inorder, preorderLeft + 1, preorderLeft + sizeLeftSubtree, inorderLeft, inorderRoot - 1);
        root->right = myBuildTree(preorder, inorder, preorderLeft + sizeLeftSubtree + 1, preorderRight, inorderRoot + 1, inorderRight);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0; i != n; ++i){
            index[inorder[i]] = i;
        }
        return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};