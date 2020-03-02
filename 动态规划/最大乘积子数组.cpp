/*
给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。

示例 1:

输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:

输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        int max = nums[0];
        int min = nums[0];
        int ans = max;
        for(int i = 1;i < size;i++){
            if(nums[i] == 0){
                max = 0;
                min = 0;
            }else{
                    int temp1 = nums[i]*max;
                    int temp2 = nums[i]*min;
                    int temp3 = temp1 > temp2 ? temp1 : temp2;
                    int temp4 = temp1 < temp2 ? temp1 : temp2;
                    max = temp3 > nums[i] ?  temp3 : nums[i];
                    min = temp4 < nums[i] ?  temp4 : nums[i];
            }
            ans = ans > max ? ans : max;
        }
        return ans;
    }
};