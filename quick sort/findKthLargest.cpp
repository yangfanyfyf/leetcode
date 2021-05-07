// 快速排序，模板
#include <vector>
using namespace std;

class Solution {
public:

    inline int partition(vector<int> &a, int l, int r){
      // x是基准元素，i是起始位置？
      int x = a[r], i = l - 1;
      // 遍历L到R之间的所有的元素
      for (int j = l; j < r; ++j){
        // 小于基准元素，那么就将数字放到开头
        if (a[j] <= x){
          swap(a[++i], a[j]);
        }
      }
      // 将基准放到中间，之前的数字都比他小，后面的数字都比他大
      swap(a[i + 1], a[r]);
      // 返回的是固定的位置
      return i + 1;
    }

    inline int randomPartition(vector<int> &a, int l, int r){
      // 随机选择基准元素，用于提高效率
      // 利用取余将数字限制在l, r内
      int i = rand() % (r - l + 1) + l;
      // 将随机数移动到一边？
      swap(a[i], a[r]);
      // 返回一次排序后，被确定的随机数的位置
      return partition(a, l, r);
    }
    // l, r指定了一个区间
    int quickSelect(vector<int>& a, int l, int r, int index){
      int q = randomPartition(a, l ,r);
      // q是随机数排序后的位置，已经确定
      // index是需要找的位置
      if (q == index){
        return a[q];
      }else {
        // 根据大小，继续搜索
        return q < index ? quickSelect(a, q + 1, r, index) : quickSelect(a, l, q - 1, index);
      }
    }
    // 主要部分
    int findKthLargest(vector<int>& nums, int k) {
      // 生成随机数种子 
      srand(time(0));
      return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
};