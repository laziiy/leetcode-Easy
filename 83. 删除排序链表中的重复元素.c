/*83. 删除排序链表中的重复元素
解题思路：本题是基于链表删除的方式，增加判断条件，判断前后两项的数值是否一致，相同的时候通过链表删除后面的节点。
在循环中不断判断，直到前后节点值不同。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode *p,*temp;
    p=head;
    while(p&&p->next) //不断比较当前节点和下个节点的值是否一致 
    {
        if(p->val==p->next->val) 
        {
            temp=p->next;
            p->next=temp->next;
            free(temp); 
        }
        else p=p->next; //不一致则往后移动节点 
    }
    return head;
}
