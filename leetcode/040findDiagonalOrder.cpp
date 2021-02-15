// 给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素，对角线遍历如下图所示。

#include <iostream>
#include <vector>
using namespace std;

// 行列之和为奇数，向左下走，否则向右上走
vector<int> findDiagonalOrder(vector<vector<int>>& matrix){
  if (matrix.size() == 0) return {};
  vector<int> ret;
  int row = matrix.size() - 1;
  int col = matrix[0].size() - 1;
  int total = row + col;
  int startX = 0;
  int startY = 0;
  for (int i = 0; i <= total; ++i){
    if (i % 2 == 0){
      if (i < row){
        startX = i;
        startY = 0; 
      }else{
        startX = row;
        startY = i - row;
      }
      while (startX >= 0 && startY <= col){
        ret.push_back(matrix[startX][startY]);
        --startX;
        ++startY;
      }
    }else{
      if (i < col){
        startY = i;
        startX = 0;
      }else{
        startY = col;
        startX = i - col;
      }
      while (startX <= row && startY >= 0){
        ret.push_back(matrix[startX][startY]);
        ++startX;
        --startY;
      }
    }
  }
  return ret;
}


int main(){ 
  vector<vector<int>> matrix{{1,2,3},{4,5,6}};
  vector<int> ret = findDiagonalOrder(matrix);
  for (auto p : ret){
    cout << p << " ";
  }
  cout << endl;
}