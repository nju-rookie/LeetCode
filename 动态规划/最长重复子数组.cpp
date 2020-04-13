/*
最长重复子串



给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。

示例 1:

输入:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
输出: 3
解释: 
长度最长的公共子数组是 [3, 2, 1]。
说明:

1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100

*/

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int ans = 0;
        int n1 = A.size(),n2 = B.size();

        //dp[i][j]代表以A中第i个，B中第j个数字结尾的子串中，最长重复子串的长度
        int dp[1000][1000] = {0};

        for(int i = 0;i < n1;i++){
            if(A[i] == B[0]){
                dp[i][0] = 1;ans = 1;
            }
        }

        for(int i = 0;i < n2;i++){
            if(A[0] == B[i]){
                dp[0][i] = 1;ans = 1;
            }
        }

        for(int i = 1;i < n1;i++){
            for(int j = 1;j < n2;j++){

            	//如果A中第i个等于B中第j个数字，只需观察A中第i-1个和B中第j-1个数字结尾的最长子串的长度
                if(A[i] == B[j]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    ans = ans > dp[i][j] ? ans : dp[i][j];
                }else
                    dp[i][j] = 0;
            }
        }
        return ans;
    }
};