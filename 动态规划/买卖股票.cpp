/*
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。

注意：你不能在买入股票前卖出股票。

 

示例 1:

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
示例 2:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        //dp[i]代表在第i天卖出最多可以赚多少钱
        vector<int> dp(n,0);
        int ans = 0;
        for(int i = 1;i < n;i++){
            if(prices[i] <= prices[i-1]){
            	//股价低于昨天，将昨天的利润在减去差价，保证大于0
                int temp = dp[i-1]+prices[i]-prices[i-1];           
                dp[i] = temp >= 0 ? temp : 0;
            }else{
            	//股价高于昨天，将昨天的利润在加上差价
                dp[i] = prices[i]-prices[i-1] + dp[i-1];
            }
            ans = ans > dp[i] ? ans : dp[i];
        }
        return ans;
    }
};



/*
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

 

示例 1:

输入: [7,1,5,3,6,4]
输出: 7
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
示例 2:

输入: [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int diff = 0;
        for(int i = 1; i < n;i++){
            diff = prices[i] - prices[i-1];
            //只需要关注股票上涨阶段
            ans = ans + (diff >= 0 ? diff : 0);
        }
        return ans;
    }
};


/*
给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
示例:

输入: [1,2,3,0,2]
输出: 3 
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]

*/


#include <algorithm>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0)
            return 0;

        //某一天可能有三种状态，持有hold，卖出sold，冷却cold
        //hold代表当天继续持有股票能得到的最大利润
        //sold代表当天继续卖出股票能得到的最大利润
        //cold代表当天继续冷却能得到的最大利润

        int cold = 0, sold = 0, hold = -prices[0];
        int pre_hold = 0;
        for(int i = 1;i < n; i++){
            pre_hold = hold;
            hold = max(hold,cold-prices[i]);
            sold = pre_hold + prices[i];
            cold = max(cold,sold);           
        }

        //sold和cold中的最大值一定大于hold
        return max(sold,cold);
    }
};


