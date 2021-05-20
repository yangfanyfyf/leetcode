// 给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。

// 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

// 作者：liweiwei1419
// 链接：https://leetcode-cn.com/leetbook/read/learning-algorithms-with-leetcode/x4yd5s/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


// 用于训练循环变量，也就是partition的过程


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      if (nums.size() == 0) return 0;
      // 双指针
      // 当不重复时，递增k，重复时交换
      int k = 0;
      for (int i = 1; i != nums.size(); ++i){
        if (nums[i] == nums[k]) {
          continue;
        }else {
          swap(nums[++k], nums[i]);
        }
      }
      // 返回的是个数，要加1
      return k + 1;
    }
};