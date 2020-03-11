/*
现在你总共有 n 门课需要选，记为 0 到 n-1。

在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]

给定课程总量以及它们的先决条件，判断是否可能完成所有课程的学习？

示例 1:

输入: 2, [[1,0]] 
输出: true
解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。
示例 2:

输入: 2, [[1,0],[0,1]]
输出: false
解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。这是不可能的。


*/

class Solution {
public:
    vector<vector<int>> graph;
    vector<int> visit;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        visit.resize(numCourses);
        for(auto num: prerequisites){
            graph[num[1]].push_back(num[0]);
        }

        for(int i = 0; i < numCourses; i++){
            if(dfs(i) == false) return false;
        }
        return true;
    }

    bool dfs(int i){
        if(visit[i] == -1) return false;        //课程i作为自己的先修课，返回false
        if(visit[i] == 1) return true;          //课程i已经可以成功修完，返回true
        visit[i] = -1;                          //课程i正在寻找先修课程
        for(auto a: graph[i]){                  //遍历i的所有先修课程
            if(!dfs(a)) return false;
        }
        visit[i] = 1;                           //如果遍历成功，则i可以成功修完
        return true;
    }
};