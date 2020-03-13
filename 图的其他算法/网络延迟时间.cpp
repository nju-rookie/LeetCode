/*
有 N 个网络节点，标记为 1 到 N。

给定一个列表 times，表示信号经过有向边的传递时间。 times[i] = (u, v, w)，其中 u 是源节点，v 是目标节点， w 是一个信号从源节点传递到目标节点的时间。

现在，我们向当前的节点 K 发送了一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1。


输入样例：

vector<vector<int>>& times
N
K

[[1,2,2],[1,3,4],[2,3,1]]
3
1

输出样例：3

*/




struct node{
    int dest;
    int len;
    friend bool operator < (const node& n1, const node& n2)
    {
        if(n1.len == n2.len)
            return n1.dest < n2.dest;
        return n1.len < n2.len;
    }

};

class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int *time = new int[N+1];
        vector<set<node>> graph;
        queue<int> q;
        q.push(K);
        graph.resize(N+1);
        for(int i = 1;i < N+1;i++){
            time[i] = 2147483647;
        }
        time[K] = 0;
        node n;
        for(auto a : times){
            n.dest = a[1];
            n.len = a[2];
            graph[a[0]].insert(n);
        }
        

        while(!q.empty()){
            int i = q.front();
            q.pop();
            if(graph[i].size() > 0){
                for(auto a : graph[i]){
                    if(time[i] + a.len < time[a.dest]){
                        time[a.dest] = time[i] + a.len;
                        q.push(a.dest);
                    }
                }
            }
        }
        int max = 0;
        for(int i = 1;i < N+1;i++){

            if(time[i] == 2147483647)
                return -1;
            max = max > time[i] ? max : time[i];
        }
        return max;
    }
};