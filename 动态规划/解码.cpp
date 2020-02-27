/*
    问题描述：一条包含字母 A-Z 的消息通过以下方式进行了编码：

'A' -> 1
'B' -> 2
...
'Z' -> 26
给定一个只包含数字的非空字符串，请计算解码方法的总数。

示例 1:

输入: "12"
输出: 2
解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。

*/


class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int *array = new int[n];
        int *dp = new int[n];
        for(int i = 0;i < n;i++)
            array[i] = s[i] - '0';
        if(array[0] == 0)
            return 0;
        else{
            dp[0] = 1;
            if(n >= 2){
            if(array[1] == 0 && array[0] >= 3)
                return 0;
            if(array[1] == 0 || 10*array[0] + array[1] > 26)
                dp[1] = 1;
            else
                dp[1] = 2;
            }
        }
        for(int i = 2;i < n;i++){
            if(array[i] != 0 && 10*array[i-1] + array[i] <= 26 && array[i-1]!=0)
                dp[i] = dp[i-1] + dp[i-2];
            else{
                if(array[i] == 0){
                    if(array[i-1] == 0 || array[i-1] >= 3 )
                        return 0;
                    else
                        dp[i] = dp[i-2];
                }else{
                    if(array[i-1] == 0 || 10*array[i-1] + array[i] > 26){
                        dp[i] = dp[i-1];
                    }
                }
            }
        }
        return dp[n-1];
    }
};