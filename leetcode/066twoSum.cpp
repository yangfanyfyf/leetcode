// 给定一个已按照 升序排列  的整数数组 numbers ，请你从数组中找出两个数满足相加之和等于目标数 target 。

// 函数应该以长度为 2 的整数数组的形式返回这两个数的下标值。numbers 的下标 从 1 开始计数 ，所以答案数组应当满足 1 <= answer[0] < answer[1] <= numbers.length 。

// 两次遍历?
// 从两侧开始，只需要遍历一次，因为数组已经有序了
vector<int> twoSum(vector<int>& numbers, int target){
  vector<int> ret;
  int p1 = 0;
  int p2 = numbers.size() - 1;
  while (numbers[p1] + numbers[p2] != target){
    if (numbers[p1] + numbers[p2] < target){
      ++p1;
    }else{
      --p2;
    }
  }
  ret.push_back(++p1);
  ret.push_back(++p2);
  return ret;
}