
/*

LEETCODE 第84题   柱状图中最大矩形
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

输入: [2,1,5,6,2,3]
输出: 10

最大面积5+5 = 10

*/



//以第i个柱子的高度作为矩形的高，构成的面积取决于它左右两边比它矮的柱子的位置j和k

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        //用递增栈进行处理
        stack<int> st;

        //-1作为哨兵
        heights.push_back(-1);

        int ans = 0;
        for(int i = 0;i <= n;i++){
                //当前元素大于栈顶元素heights[top]
                //如果以第top个柱子的高度作为矩形的高，构成的面积取决于它左右两边比它矮的柱子的位置j和k
                //右边比top矮的柱子即为i，左边比top矮的柱子即为top出栈后新的栈顶元素
                while(st.size() != 0 && heights[st.top()] > heights[i]){
                    int temp = st.top();    st.pop();
                    int left = st.size() == 0 ? -1 : st.top();
                    int area = (i - left -1) * heights[temp];
                    ans = ans > area ? ans : area;
                }
                st.push(i);
        }
        return ans;
    }
};