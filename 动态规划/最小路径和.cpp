/*

最小路径和：	给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
			说明：每次只能向下或者向右移动一步。

参考样例


输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。


*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> path;
        path.resize(m);
        for(int i = 0;i < m;i++)
            path[i].resize(n);

        /*
        	对于第0行和第0列，只有一种走法
			对于其他行和列，有两种选择，从上方的一格往下/从左方的一格往右，所以每次选取二者中较短的一条即可
		*/
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(i == 0 && j == 0)
                    path[0][0] = grid[0][0];
                if(i == 0 && j != 0)
                    path[0][j] = grid[0][j] + path[0][j-1];
                if(j == 0 && i != 0)
                    path[i][0] = grid[i][0] + path[i-1][0];
                if(i != 0 && j!= 0){
                    int temp = path[i-1][j] < path[i][j-1] ? path[i-1][j]:path[i][j-1];
                    path[i][j] = temp + grid[i][j]; 
                }
            }
        }
        return path[m-1][n-1];
    }
};