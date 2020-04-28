/**

合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* listmerge(ListNode* l1,ListNode* l2)
{
    //创建头结点head（但是不使用，只是为了方便）
    //创建tail来遍历两个链表l1,l2
    ListNode head, *tail = &head;
    while(l1 && l2){
        if(l1 -> val < l2 -> val){
            tail -> next = l1;
            l1 = l1 -> next;
        }else{
            tail -> next = l2;
            l2 = l2 -> next;
        }
        tail = tail -> next;
    }

    //可能有一条链表并未遍历到底
    tail -> next = (l1 == NULL) ? l2 : l1;
    return head.next;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = NULL;
        int n = lists.size();
        //循环合并链表
        for(int i = 0;i < n;i++)
            ans = listmerge(ans,lists[i]);
        return ans;
    }
};