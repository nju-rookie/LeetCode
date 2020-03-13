/*
给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

示例:

输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

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
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> answer;
        if(root == NULL)
            return answer;
        q.push(root);
        while(q.size() > 0){
            answer.push_back(q.back()->val);
            int size = q.size();
            for(int i = 0;i < size;i++){
                TreeNode *p = q.front();
                q.pop();
                if(p -> left != NULL)  q.push(p -> left);
                if(p -> right != NULL) q.push(p -> right);
            }
        }
        return answer;
    }
};