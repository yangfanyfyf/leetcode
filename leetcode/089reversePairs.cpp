// 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。

// 输入一个数组，求出这个数组中的逆序对的总数。

// 遍历
// 超时！
class Solution {
public:
    int reversePairs(vector<int>& nums) {
      int ret = 0;
      int n = nums.size();
      if (n == 0){
        return 0;
      }
      for (int i = 0; i != n - 1; ++i){
        for (int j = i + 1; j != n; ++j){
          if (nums[i] > nums[j]){
            ++ret;
          }
        }
      }
      return ret;
    }
};


class Solution {
public:
    int mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r){
      if (l >= r){
        return 0;
      }
      int mid = (l + r) / 2;
      int inv_count = mergeSort(nums, tmp, l, mid) + mergeSort(nums, tmp, mid + 1, r);
      int i= l, j = mid + 1, pos = l;
      while (i <= mid && j <= r){
        if (nums[i] <= nums[j]) {
          tmp[pos] = nums[i];
          ++i;
          inv_count += (j - (mid + 1));
        }else {
          tmp[pos] = nums[j];
          ++j;
        }
        ++pos;
      }
      for (int k = i; k <= mid; ++k){
        tmp[pos++] = nums[k];
        inv_count += (j - (mid + 1));
      }
      for (int k = j; k <= r; ++k){
        tmp[pos++] = nums[k];
      }
      copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
      return inv_count;
    }
    int reversePairs(vector<int>& nums) {
      int n = nums.size();
      vector<int> tmp(n);
      return mergeSort(nums, tmp, 0, n - 1);
    }
};