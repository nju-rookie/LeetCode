/*
有一个二维矩阵 grid ，每个位置要么是陆地（记号为 0 ）要么是水域（记号为 1 ）。

我们从一块陆地出发，每次可以往上下左右 4 个方向相邻区域走，能走到的所有陆地区域，我们将其称为一座「岛屿」。

如果一座岛屿 完全 由水域包围，即陆地边缘上下左右所有相邻区域都是水域，那么我们将其称为 「封闭岛屿」。

请返回封闭岛屿的数目。

 

示例 1：



输入：grid = 
[[1,1,1,1,1,1,1,0],
[1,0,0,0,0,1,1,0],
[1,0,1,0,1,1,1,0],
[1,0,0,0,0,1,0,1],
[1,1,1,1,1,1,1,0]]
输出：2
解释：
灰色区域的岛屿是封闭岛屿，因为这座岛屿完全被水域包围（即被 1 区域包围）。


*/




bool dfs(vector<vector<int>>& grid,int n,int m,int i,int j);
vector<vector<bool>> judge;
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        judge.resize(n);
        for(int i = 0;i < n;i++){
            judge[i].resize(m);
        }

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                judge[i][j] = false;
            }
        }

        int sum = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j] == 0 && judge[i][j] == false && i != 0 && j != 0 && i != n-1 && j != m-1){
                    
                    bool flag = dfs(grid,n,m,i,j);
                    sum = flag == true ? sum+1 : sum;
                }
            }
        }
        return sum;
    }
};

bool dfs(vector<vector<int>>& grid,int n,int m,int i,int j)
{
    judge[i][j] = true;
    
    if(i == 0 || j == 0 || i == n-1 || j == m-1){
        return false;
    }
    else{
        bool flag1 = true,flag2 = true,flag3 = true ,flag4 = true;
        if(grid[i-1][j] == 0 && judge[i-1][j] == false){
            flag1 = dfs(grid,n,m,i-1,j);
            
        }
        if(grid[i+1][j] == 0 && judge[i+1][j] == false){
            flag2 = dfs(grid,n,m,i+1,j);
           
        }
        if(grid[i][j-1] == 0 && judge[i][j-1] == false){
            flag3 = dfs(grid,n,m,i,j-1);
 
        }
        if(grid[i][j+1] == 0 && judge[i][j+1] == false){
            flag4 = dfs(grid,n,m,i,j+1);
        }
        if(!flag1 || !flag2 || !flag3 || !flag4)
            return false;
    }
    return true;

}