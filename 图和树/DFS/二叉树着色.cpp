/**
有两位极客玩家参与了一场「二叉树着色」的游戏。游戏中，给出二叉树的根节点 root，树上总共有 n 个节点，且 n 为奇数，其中每个节点上的值从 1 到 n 各不相同。

 

游戏从「一号」玩家开始（「一号」玩家为红色，「二号」玩家为蓝色），最开始时，

「一号」玩家从 [1, n] 中取一个值 x（1 <= x <= n）；

「二号」玩家也从 [1, n] 中取一个值 y（1 <= y <= n）且 y != x。

「一号」玩家给值为 x 的节点染上红色，而「二号」玩家给值为 y 的节点染上蓝色。

 

之后两位玩家轮流进行操作，每一回合，玩家选择一个他之前涂好颜色的节点，将所选节点一个 未着色 的邻节点（即左右子节点、或父节点）进行染色。

如果当前玩家无法找到这样的节点来染色时，他的回合就会被跳过。

若两个玩家都没有可以染色的节点时，游戏结束。着色节点最多的那位玩家获得胜利 ✌️。

 

现在，假设你是「二号」玩家，根据所给出的输入，假如存在一个 y 值可以确保你赢得这场游戏，则返回 true；若无法获胜，就请返回 false。

 
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int t;
TreeNode *ta;
void search(TreeNode* p);
int count(TreeNode* p);
class Solution {
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        t = x;
        search(root);
        int left = 0,right = 0;
        
        if(ta -> left != NULL)
        {
            left = count(ta-> left) ;
            if(left > n/2)
                return true;
        }
        if(ta -> right != NULL)
        {
            right = count(ta->right) ;
            if(right > n/2)
                return true;
        }
        if(left + right + 1 <= n/2)
            return true;
        return false;
    }
};
int count(TreeNode* p)
{
    if(p == NULL)
        return 0;
    else
        return 1 + count(p -> left) + count(p -> right);
}
void search(TreeNode* p)
{
    if(p -> val == t)
        ta = p;
    else{
        if(p -> left != NULL)
            search(p -> left);
        if(p -> right != NULL)
            search(p -> right);
    }
}