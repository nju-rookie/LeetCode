

/*

接雨水

给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。


上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水

*/


#include <algorithm>
class Solution {
public:
    int trap(vector<int>& height) {

        int size = height.size();
        stack<int> st;
        int ans = 0;
        for(int i = 0;i < size;i++){

        	//递减栈，需要找到两边比自己高的
            while(st.size() != 0 && height[i] > height[st.top()])
            {
                int temp = st.top(); st.pop();
                if(st.size() != 0){
                    int left = st.top();
                    int len = i - left - 1;

                    //以自身高度和左/右高柱子中较矮的一根之间的差值作为矩形高，构成的矩形为接水量
                    ans += len*(min(height[i],height[left]) - height[temp]);
                }
            }
            st.push(i);
        }
        return ans;
    }
};