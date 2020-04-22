/*

不用递归的方法给出N叉树的前序遍历
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        stack<Node*> s;
        vector<int> ans;
        Node* p = root;
        while(p != NULL){
            while(p != NULL){


                //  STEP1:把当前结点的值放入ans中
                //  STEP2:把当前结点的所有右子树压栈（注意次序）
                //  SETP3:把当前结点的最左子树赋给当前结点
                ans.push_back(p -> val);
                
                int n = p -> children.size();
                for(int i = n-1;i >= 1;i--){
                    s.push(p->children[i]);
                }
                if(n != 0)
                    p = p -> children[0];
                if(n == 0)
                    break;
            }
            if(s.size()!=0){
                p = s.top();
                s.pop();
            }else
                break;
            
        }
        return ans;
    }
};