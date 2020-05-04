//跳跃游戏


/*
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
说明:

假设你总是可以到达数组的最后一个位置。

*/


//动态规划（超时）
#include<algorithm>
#define MAX 2147483640
class Solution {
public:
    int jump(vector<int>& nums) {
       int n = nums.size();
       vector<int> dp(n,MAX);
       dp[0] = 0;
       for(int i = 0;i < n-1;i++){
           for(int j = i+1;j <= min(i + nums[i],n-1);j++){
               dp[j] = min(dp[i] + 1, dp[j]);
           }
       }
       return dp[n-1];
    }
};


//动态规划+贪心

//先证明引理 dp[i] >= dp[i-1]，所以对于每个点K,只需要更新最早到达K的跳跃次数即可。

//P是最先的可以跳到K的点， dp[K] = dp[P] + 1, dp[P+1 -> K-1] + 1 >= dp[P] + 1


class Solution {
public:
    int jump(vector<int>& nums) {
       int n = nums.size();
       vector<int> dp(n,0);

       //last + nums[last]用于维护当前能跳到的最远的点

       for(int i = 1,last = 0;i < n;i++){
           while(last < n && last + nums[last] < i) last++;
           dp[i] = dp[last] + 1;
       }
       return dp[n-1];
    }
};
