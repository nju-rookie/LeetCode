/*

打家劫舍（一）


你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

示例 1:

输入: [1,2,3,1]
输出: 4
解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
示例 2:

输入: [2,7,9,3,1]
输出: 12
解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。

*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        if(n == 0)
            return 0;
        if(n == 1)
            return nums[0];
        dp[0] = nums[0];
        dp[1] = nums[1]>nums[0]?nums[1]:nums[0];

        for(int i = 2;i < n;i++){
            int temp = dp[i-2]+nums[i];
            dp[i] = dp[i-1]>temp?dp[i-1]:temp;
        }
        return dp[n-1];

    }
};



/*

打家劫舍（二）

你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

示例 1:

输入: [2,3,2]
输出: 3
解释: 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
示例 2:

输入: [1,2,3,1]
输出: 4
解释: 你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
     偷窃到的最高金额 = 1 + 3 = 4 。

*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n,0);
        vector<int> dp2(n,0);
        if(n == 0)
            return 0;
        if(n == 1)
            return nums[0];
        dp1[0] = nums[0];
        dp1[1] = nums[1]>nums[0]?nums[1]:nums[0];
        dp2[1] = nums[1];
        int temp;
        for(int i = 2;i < n;i++){
            temp = nums[i]+dp1[i-2];
            dp1[i] = temp>dp1[i-1]?temp:dp1[i-1];
            temp = nums[i]+dp2[i-2];
            dp2[i] = temp>dp2[i-1]?temp:dp2[i-1];
        }
        return (dp1[n-2]>dp2[n-1]?dp1[n-2]:dp2[n-1]);
    }
};




/*

打家劫舍（三）
在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

*/


typedef pair<int,int> newpair;
newpair dfs(TreeNode* p);
class Solution {
public:
    int rob(TreeNode* root) {
        if(root == NULL)
            return 0;
        newpair pair = dfs(root);
        return pair.first>pair.second?pair.first:pair.second;
    }
};
newpair dfs(TreeNode* p)
{

    if(p == NULL){
        newpair pair(0,0);
        return pair;
    }
    else{
        newpair pair1 = dfs(p->left);
        newpair pair2 = dfs(p->right);
        int temp1 = pair1.first > pair1.second ? pair1.first : pair1.second;
        int temp2 = pair2.first > pair2.second ? pair2.first : pair2.second;
        newpair ans(p->val + pair1.second + pair2.second ,temp1+temp2);
        return ans;
    }
}



