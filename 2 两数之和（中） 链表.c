/*本题的设计思路有：
1、想通过链表转换为——数字，然后数值按位相加，再取余数，从低位到高位存入链表，读取链表值
2、递归方法实现对链表的调用（进位考虑在每一次按位计算中，加和完之后就%10取余数算进位，/10存入） 
3、迭代的方法，使用while循环一直迭代，直到两个链表都为空。
初学链表，写起来感觉逻辑代码实现总很卡，学习参考了代码：https://blog.csdn.net/qq_39929929/article/details/102802508
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    int c=0;
    struct ListNode *head,*cur,*p;
    head=(struct ListNode*)malloc(sizeof (struct ListNode)); //分配了一个节点
    head->next=NULL;//初始化下一个节点为空
    cur=head;
    while(l1||l2||c)*、
    {   /*这里一小段最开始没写，报错一直显示存入的为空，因为初始化cur->next=NULL，如果直接cur=cur->next,cur里将没有值*/
        p=(struct ListNode*)malloc(sizeof (struct ListNode)); //每次都新分配一个节点，不断在原结点上插入新结点进行运算
        p->next=NULL; 
        cur->next=p;
        cur=p;
        if(l1!=NULL)
        {
            c=c+l1->val;
            l1=l1->next;
        }
        else c+=0;
        if(l2!=NULL)
        {
            c=c+l2->val;
            l2=l2->next;
        }
        else c+=0;
        cur->val=c%10;
        c=c/10;
    }
    struct ListNode *t=head;
    head=head->next;
    free(t);
    return head;
}

