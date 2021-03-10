// 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。

// 在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。

// 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

// 说明：你不能倾斜容器

// 作者：liweiwei1419
// 链接：https://leetcode-cn.com/leetbook/read/learning-algorithms-with-leetcode/x404gd/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// 遍历，超时
class Solution {
public:
    int maxArea(vector<int>& height) {
      int ret = 0;
      int len = height.size();
      for (int i = 0; i != len; ++i){
        for (int j = i + 1; j != len; ++j){
          int area = min(height[i], height[j]) * (j - i);
          if (area > ret)
            ret = area;
        }
      }
      return ret;
    }
};

// 双指针
// 移动对应值较小的那个指针
// 因为这个值限制了面积的最大值，就算移动另外一个，面积也不会变大
class Solution {
public:
    int maxArea(vector<int>& height) {
      int left = 0, right = height.size() - 1;
      int ret = 0;
      while (left < right){
        int area = min(height[left], height[right]) * (right - left);
        ret = max(area, ret);
        if (height[left] < height[right]){
          ++left;
        }else {
          --right;
        }
      }
      return ret;
    }
};