// 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

// 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
/*
void sortColors(vector<int>& nums){
  sort(nums.begin(), nums.end());
}

// 遍历，统计0，1，2的个数
void sortColors(vector<int>& nums){
  int num0 = 0, num1 = 0, num2 = 0;
  for (auto x : nums){
    if (x == 0){
      ++num0;
    }else if (x == 1){
      ++num1;
    }else if(x == 2){
      ++num2;
    }
  }
  int i =0;
  for (; i != num0; ++i){
    nums[i] = 0;
  }
  for (; i != num0 + num1; ++i){
    nums[i] = 1;
  }
  for (; i != nums.size(); ++i){
    nums[i] = 2;
  }
}
*/
// 使用两个指针，指向数组开头和最后
// 这两个指针将数组分为三个部分
void sortColors(vector<int>& nums){
  int num0 = 0;
  int num2 = nums.size() - 1;
  for (int i = 0; i <= num2; ++i){
    while (nums[i] == 2 && i <= num2){
      swap(nums[i], nums[num2]);
      // cout << nums[num2] << "  ";
      // if (i != num2)
      --num2;
    }
    if (nums[i] == 0){
      swap(nums[i], nums[num0]);
      // if (i != num0)
        ++num0;
    }
    
    cout << nums[i] << "  ";
    // if (i > num2) break;
  }
}

// void sortColors(vector<int>& nums) {
//   int n = nums.size();
//   int p0 = 0, p1 = 0;
//   for (int i = 0; i != n; ++i){
//     if (nums[i] == 1){
//       swap(nums[i], nums[p1]);
//       ++p1;
//     }else if (nums[i] == 0){
//       swap(nums[i], nums[p0]);
//       // 头部可能有1，交换出去会报错
//       if (p0 < p1) {
//         swap(nums[i], nums[p1]);
//       }
//       ++p0;
//       ++p1;
//     }
//   }
// }

int main(){
  vector<int> nums = {2,1,2};
  // moveZeroes(nums);
  sortColors(nums);
  cout << endl;
  for (auto x : nums){
    cout << x << " ";
  }
  cout << endl;
  // cout << "length == " << k << endl;
  return 0;
}