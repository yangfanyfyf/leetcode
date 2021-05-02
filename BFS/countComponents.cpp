// 给定编号从 0 到 n-1 的 n 个节点和一个无向边列表（每条边都是一对节点），

// 请编写一个函数来计算无向图中连通分量的数目。
#include <vector>
using namespace std;

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
      // 构建图
      vector<unordered_set<int>> graph(n);
      vector<bool> visited(n, false);
      for(const auto &p : edges){
        graph[p[0]].insert(p[1]);
        graph[p[1]].insert(p[0]);
      }
      int count = 0;
      for (int i = 0; i < n; ++i){
        queue<int> q{{i}}; // 这是什么初始化方法？？？
        if (!visited[i]){
          ++count;
          while(!q.empty()){
            auto cur = q.front();
            q.pop();
            if (visited[cur]){
              continue;
            }
            visited[cur] = true;
            for (const auto &neighbor : graph[cur]){
              q.push(neighbor);
            }
          }
        }
      }
      return count;
    }
};