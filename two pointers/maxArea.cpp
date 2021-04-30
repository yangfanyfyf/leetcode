// 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。

// 在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。

// 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

// 作者：liweiwei1419
// 链接：https://leetcode-cn.com/leetbook/read/learning-algorithms-with-leetcode/x1qzyg/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
      int left = 0;
      int right = height.size() - 1;
      int ret = 0;
      while (left < right){
        ret = max(ret, (right - left) * min(height[left], height[right]));
        if (height[left] < height[right]){
          ++left;
        }else {
          --right;
        }
      }
      return ret;
    }
};