// 编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零

#include <vector>
#include <iostream>
using namespace std;

// 使用一个辅助矩阵？
// 或者单独记录所有0的坐标
// 时间复杂度：4次遍历，O(nm)
// 空间复杂度：用到了两个数组，O(n+m)
void setZeroes(vector<vector<int>>& matrix) {
  vector<int> recordX;
  vector<int> recordY;
  int row = matrix.size();
  int col = matrix[0].size();
  for (int i = 0; i != row; ++i){
    for (int j = 0; j != col; ++j){
      if (!matrix[i][j]){
        recordX.push_back(i);
        recordY.push_back(j);
      }
    }
  }
  // 遍历对应行，将该行置0
  for (int i = 0; i != recordX.size(); ++i){
    for (int j = 0; j != col; ++j){
      matrix[recordX[i]][j] = 0;
    }
  }
  // 遍历对应列，将该列置0
  for (int j = 0; j != recordY.size(); ++j){
    for(int i = 0; i != row; ++i){
      matrix[i][recordY[j]] = 0;
    }
  }
}

int main(){
  vector<vector<int>> nums{{1,1,1},{1,0,1},{1,2,3}};
  setZeroes(nums);
  for (int i = 0; i != nums.size(); ++i){
    for (int j = 0; j != nums[0].size(); ++j){
      cout << nums[i][j] << " ";
    }
    cout << endl;
  }
}