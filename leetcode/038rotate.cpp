// 给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。

// 不占用额外内存？
#include <vector>
#include <iostream>
using namespace std;

// 使用辅助数组
// 行变成了列
void rotate(vector<vector<int>>& matrix) {
  vector<vector<int>> temp = matrix;
  int len = matrix.size();
  for (int i = 0; i != len; ++i){
    for (int j = 0; j != len; ++j){
      temp[j][len - i - 1] = matrix[i][j];
    }
  }
  matrix = temp;
}

// 原地旋转
void rotate(vector<vector<int>>& matrix) {
  int n = matrix.size();
  for (int i = 0; i < n / 2; ++i){
    for (int j = 0; j < (n + 1) / 2; ++j){
      int temp = matrix[i][j];
      matrix[i][j] = matrix[n - j - 1][i];
      matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
      matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
      matrix[j][n - i - 1] = temp;
    }
  }
}

// 反转矩阵
void rotate(vector<vector<int>>& matrix) {
  int n = matrix.size();
  for (int i = 0; i < n / 2; ++i){
    for (int j = 0; j < n; ++j){
      swap(matrix[i][j], matrix[n - i - 1][j]);
    }
  }
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < i; ++j){
      swap(matrix[i][j], matrix[j][i]);
    }
  }
}