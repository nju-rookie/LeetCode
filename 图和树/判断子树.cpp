/*

另一个树的子树


给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。

示例 1:
给定的树 s:

     3
    / \
   4   5
  / \
 1   2
给定的树 t：

   4 
  / \
 1   2
返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。

示例 2:
给定的树 s：

     3
    / \
   4   5
  / \
 1   2
    /
   0
给定的树 t：

   4
  / \
 1   2
返回 false。


*/



//解法一：非常不优雅
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

vector<TreeNode*> c;
void search(TreeNode *p, int target);
bool compare(TreeNode *t,TreeNode *p);
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        c.resize(0);
        search(s,t -> val);
        for(auto i : c)
            if(compare(t,i) == true)   return true;
        return false;
    }
};

void search(TreeNode *p, int target)
{
    if(p == NULL)
        return;
    else{
        if(p -> val == target){
            c.push_back(p);
        }
        search(p -> left,target);
        search(p -> right,target);
        return;
    }
}

bool compare(TreeNode *t,TreeNode *p)
{
    if(t == NULL || p == NULL)
        return t == p;
    else{
        return p->val == t->val & compare(t->left,p->left) & compare(t->right,p->right);
    }
}


//解法二

class Solution {
public:
    bool check(TreeNode *o, TreeNode *t) {
        if (!o && !t) return true;
        if ((o && !t) || (!o && t) || (o->val != t->val)) return false;
        return check(o->left, t->left) && check(o->right, t->right);
    }

    bool dfs(TreeNode *o, TreeNode *t) {
        if (!o) return false;
        return check(o, t) || dfs(o->left, t) || dfs(o->right, t);
    }

    bool isSubtree(TreeNode *s, TreeNode *t) {
        return dfs(s, t);
    }
};
