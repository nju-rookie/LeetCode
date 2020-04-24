/*
路径总和

给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void dfs(TreeNode* p,int sum,vector<int>& path,vector<vector<int>>& ans);

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        vector<vector<int>> ans;
        dfs(root,sum,path,ans);
        return ans;
    }
};

void dfs(TreeNode* p,int sum,vector<int>& path,vector<vector<int>>& ans)
{
    if(p == NULL)
        return;
    if(!p -> left&& !p -> right){
        if(p -> val == sum){
            path.push_back(p->val);
            ans.push_back(path);
            path.pop_back();
        }
    }else{
        path.push_back(p->val);
        if(p -> left)  dfs(p -> left,sum - p->val,path,ans);
        if(p -> right)  dfs(p -> right, sum - p->val,path,ans);
        path.pop_back();
    }return;
}