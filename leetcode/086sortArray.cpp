// 选择排序
// 超时
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
      int n = nums.size();
      if (n == 0){
        return {};
      }
      int min = 0;
      for (int i = 0; i != n; ++i){
        min = nums[i];
        int minIndex = i;
        for (int j = i; j != n; ++j){
          if (nums[j] < min){
            min = nums[j];
            minIndex = j;
          }
        }
        int temp = nums[minIndex];
        nums[minIndex] = nums[i];
        nums[i] = temp;
      }
      return nums;
    }
};


// 插入排序
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
      int len = nums.size();
      for (int i = 1; i != len; ++i){
        int temp = nums[i];
        int j = i;
        while (j > 0 && nums[j - 1] > temp) {
          nums[j] = nums[j - 1];
          --j;
        }
        nums[j] = temp;
      }
      return nums;
    }
};


// 归并排序
class Solution {
    vector<int> tmp;
    void mergeSort(vector<int>& nums, int l, int r){
      if (l >= r)
        return;
      
      int mid = l + (r - l) / 2;
      // int mid = (l + r) >> 1;
      mergeSort(nums, l, mid);
      mergeSort(nums, mid + 1, r);
      int i = l;
      int j = mid + 1;
      int cnt = 0;
      // 归并排序
      while (i <= mid && j <= r){
        if (nums[i] <= nums[j]){
          tmp[cnt++] = nums[i++];
        }else{
          tmp[cnt++] = nums[j++];
        }
      }
      // 处理当一个数组已空时的情况
      while (i <= mid){
        tmp[cnt++] = nums[i++];
      }
      while(j <= r){
        tmp[cnt++] = nums[j++];
      }
      // 将排序后的数组放回原来的数组中
      for(int i = 0; i < r - l + 1; ++i){
        nums[i + l] = tmp[i];
      }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
      tmp.resize((int)nums.size(), 0);
      mergeSort(nums, 0, (int)nums.size() - 1);
      return nums;
    }
};