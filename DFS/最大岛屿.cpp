/*
给定一个包含了一些 0 和 1的非空二维数组 grid , 一个 岛屿 是由四个方向 (水平或垂直) 的 1 (代表土地) 构成的组合。你可以假设二维矩阵的四个边缘都被水包围着。

找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)

示例 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
对于上面这个给定矩阵应返回 6。注意答案不应该是11，因为岛屿只能包含水平或垂直的四个方向的‘1’。

*/




int dfs(int i,int j,vector<vector<bool>>& record,vector<vector<int>>& grid,int n,int m);
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> record;
        record.resize(n);
        for(int i = 0;i < n;i++)
            record[i].resize(m);
        for(int i = 0;i < n;i++){
            for(int j= 0;j < m;j++){
                record[i][j] = false;
            }
        }

        int max = 0;
        for(int i = 0;i < n;i++){
            for(int j= 0;j < m;j++){
                if(grid[i][j] == 1 && record[i][j] == false){
                    int area = dfs(i,j,record,grid,n,m);
                    max = max > area ? max : area;
                }
            }
        }
        return max;
    }
};

int dfs(int i,int j,vector<vector<bool>>& record,vector<vector<int>>& grid,int n,int m)
{
    record[i][j] = true;
    int sum = 1;
    if(i-1 >= 0 &&  grid[i-1][j] == 1 && record[i-1][j] == false)
        sum = sum + dfs(i-1,j,record,grid,n,m);
    if(i+1 < n &&  grid[i+1][j] == 1 && record[i+1][j] == false)
        sum = sum + dfs(i+1,j,record,grid,n,m);
    if(j+1 < m &&  grid[i][j+1] == 1 && record[i][j+1] == false)  
        sum = sum + dfs(i,j+1,record,grid,n,m);
    if(j-1 >= 0 &&  grid[i][j-1] == 1 && record[i][j-1] == false)  
        sum = sum + dfs(i,j-1,record,grid,n,m);
    return sum;
}