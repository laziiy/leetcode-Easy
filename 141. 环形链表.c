//141. 环形链表
//方法一：不好,比较是否有重复，重复即有环形指针 
bool hasCycle(struct ListNode *head) 
{
    struct ListNode *Addr[10000]={0};//初始化，且10000数字不能确定 
    int i=0,j;
    while(head!=NULL){
        for(j=0;j<10000;j++)
            if(head==Addr[j]) return 1;
        Addr[i]=head;
        head=head->next;
        i++;
    }
    return 0;
}

//方法二：参考题解思路，构建一个快指针，一个慢指针，如果能相遇，则证明有环路。（要考虑是否重复为空的情况） 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) 
{
    struct ListNode *slow,*fast;
    fast=head;
    slow=head;
    if(head==NULL) return 0;
    while(slow->next!=NULL&fast->next!=NULL)
    {
        if(slow->next==fast->next->next) return 1;
            slow=slow->next;
            fast=fast->next->next;
        if(fast==NULL||slow==NULL) return 0;
    }
    return 0;
}
