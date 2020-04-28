/*

给定一个二叉树，在树的最后一行找到最左边的值

 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 

*/


//bfs

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()!=0){
            int size = q.size();
            ans = q.front() -> val;
            for(int i = 0;i < size;i++){
                TreeNode* p = q.front();
                if(p->left!=NULL)   q.push(p->left);
                if(p->right!=NULL)   q.push(p->right);
                q.pop();
            }
        }
        return ans;
    }
};

//dfs



int depth,ans;
void dfs(TreeNode* p , int d);
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        depth=-1;   ans=0;
        dfs(root,0);
        return ans;
    }
};

void dfs(TreeNode* p , int d)
{
    if(p == NULL)
        return;
    else{
        if(d > depth){
            ans = p -> val;
            depth = d;
        }
        dfs(p -> left, d + 1);
        dfs(p -> right,d + 1);
    }
}