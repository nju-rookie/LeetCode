/*
根据每日 气温 列表，请重新生成一个列表，对应位置的输出是需要再等待多久温度才会升高超过该日的天数。如果之后都不会升高，请在该位置用 0 来代替。

例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。

提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。


*/


typedef pair<int,int> p;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ans(n,0);

        //栈中元素为（日期，温度）数据对
        stack<p> stack;
        for(int i = 0;i < n;i++){

        	//栈中温度必须呈现递减序列
            while(stack.size()!=0 && T[i] > stack.top().second){
                ans[stack.top().first] = i - stack.top().first;
                stack.pop();
            }
            p newpair(i,T[i]);
            stack.push(newpair);
        }
        return ans;
    }
};