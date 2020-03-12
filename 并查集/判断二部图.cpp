/*
给定一个无向图graph，当这个图为二分图时返回true。

如果我们能将一个图的节点集合分割成两个独立的子集A和B，并使图中的每一条边的两个节点一个来自A集合，一个来自B集合，我们就将这个图称为二分图。

graph将会以邻接表方式给出，graph[i]表示图中与节点i相连的所有节点。每个节点都是一个在0到graph.length-1之间的整数。这图中没有自环和平行边： graph[i] 中不存在i，并且graph[i]中没有重复的值。


示例 1:
输入: [[1,3], [0,2], [1,3], [0,2]]
输出: true
解释: 
无向图如下:
0----1
|    |
|    |
3----2
我们可以将节点分成两组: {0, 2} 和 {1, 3}。

示例 2:
输入: [[1,2,3], [0,2], [0,1,3], [0,2]]
输出: false
解释: 
无向图如下:
0----1
| \  |
|  \ |
3----2
我们不能将节点分割成两个独立的子集。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/is-graph-bipartite
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/


class Solution {
public:
    vector<int> union_;
    vector<int> enemy;
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        union_.resize(n);
        enemy.resize(n);
        for(int i = 0;i < n;i++){
            union_[i] = i;
            enemy[i] = -1;
        }
        for(int i = 0;i < n;i++){
            int size = graph[i].size();
            for(int j = 0;j < size;j++){
                if(enemy[i] == -1)
                    enemy[i] = graph[i][j];
                if(enemy[graph[i][j]] == -1)
                    enemy[graph[i][j]] = i;
                int f1 = find(i);
                int f2 = find(graph[i][j]);
                if(f1 == f2)
                    return false;
                else
                    union_[f2] = find(enemy[i]);
            }     
        } 
        return true;
    }
    int find(int x){
        while(union_[x] != x)
            x = union_[x];
        return x;
    }
};