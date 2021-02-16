// 你需要帮助他们用最少的索引和找出他们共同喜爱的餐厅。 如果答案不止一个，则输出所有答案并且不考虑顺序。 你可以假设总是存在一个答案。

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
  vector<string> ret;
  unordered_map<string, int> map1;
  unordered_map<string, int> map2;
  for (int i = 0; i != list1.size(); ++i){
    map1.insert(make_pair(list1[i], i));
  }
  for (int i = 0; i != list2.size(); ++i){
    if (map1.count(list2[i])){
      map2.insert(make_pair(list2[i], map1[list2[i]] + i));
    }
  }
  // 如何根据second的值排序？？？？？
  int min = 10000;
  for (auto it = map2.begin(); it != map2.end(); ++it){
    if (it->second < min)
      min = it->second;
  }

  for (auto it = map2.begin(); it != map2.end(); ++it){
    if (it->second == min){
      ret.push_back(it->first);
    }
  }
  return ret;
}