/*
给你一棵二叉树，请你返回层数最深的叶子节点的和。

*/



//bfs解法
void search(TreeNode* p,int depth);
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while(q.size()!=0){
            int flag = 0,sum=0;
            int size = q.size();
            for(int i = 0;i < size;i++){
                TreeNode* p = q.front();
                if(p->left!=NULL){q.push(p->left);flag=1;}
                if(p->right!=NULL){q.push(p->right);flag=1;}
                sum+=p->val;
                q.pop();
            }
            if(flag == 0)
                ans = sum;
        } 
        return ans;
    }
};


//dfs解法

int maxdep,ans;
void dfs(TreeNode* p,int dep);
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        maxdep=-1,ans=0;
        dfs(root,0);
        return ans;
    }
};

void dfs(TreeNode* p,int dep)
{
    if(p == NULL)
        return;
    else{

        if(dep == maxdep){
            ans += p -> val;
        }

        if(dep > maxdep){
            maxdep = dep;
            ans = p -> val;
        }
        dfs(p->left,dep+1);
        dfs(p->right,dep+1);
    }
}
