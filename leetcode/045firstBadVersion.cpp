// 假设你有 n 个版本 [1, 2, ..., n]，你想找出导致之后所有版本出错的第一个错误的版本。

// 你可以通过调用 bool isBadVersion(version) 接口来判断版本号 version 是否在单元测试中出错。实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。

// 如果返回false，则向后查找
// 速度太慢了
int firstBadVersion(int n){
  int left = 1, right = n;
  while (left <= right){
    int mid = left + (right - left) / 2;
    if (isBadVersion(mid) == true && isBadVersion(mid - 1) == false ){
      return mid;
    }else if(isBadVersion(mid) == true){
      right = mid - 1;
    }else if(isBadVersion(mid) == false){
      left = mid + 1;
    }
  }
  return -1;
}


int firstBadVersion(int n) {
  int left = 1, right = n;
  while (left < right){
    int mid = left + ((right - left) >> 1);
    if (!isBadVersion(mid) && isBadVersion(mid + 1)) return mid + 1;
    if (!isBadVersion(mid) && !isBadVersion(mid + 1)) left = mid + 1;
    if (isBadVersion(mid + 1) && isBadVersion(mid + 2)) right = mid;
  }
  return 1;
}