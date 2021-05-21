// 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

// 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。



// 作者：liweiwei1419
// 链接：https://leetcode-cn.com/leetbook/read/learning-algorithms-with-leetcode/x4fxbm/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// 三项切分的快速排序

class Solution {
public:
    void quickSort(vector<int> &nums, int left, int right){
      if (left >= right) return;
      // 在范围内随机取一个数
      int randomIndex = left + rand() % (right - left + 1);
      // 把这个数字放在数组的最前面
      swap(nums[randomIndex], nums[left]);
      // 快排的一般步骤，取一个pivot
      int pivot = nums[left];
      int lt = left;
      int gt = right + 1;
      int i = left + 1;
      while (i < gt){
        if (nums[i] < pivot){
          swap(nums[i++], nums[++lt]);
        }else if (nums[i] == pivot){
          ++i;
        }else {
          swap (nums[i], nums[--gt]);
        }
      }
      swap(nums[left], nums[lt]);
      quickSort(nums, left, lt - 1);
      quickSort(nums, gt, right);
    }
    void sortColors(vector<int>& nums) {
      srand(time(0));
      int len = nums.size();
      quickSort(nums, 0, len - 1);
    }
};