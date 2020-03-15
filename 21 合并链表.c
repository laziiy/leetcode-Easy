/*21 合并链表*/
/*本题在写的时候还是遇到了bug，一定要定义头指针，因为进行链表数据内容比较时，将链表的数据进行了移位，如果不设定头指针，数据虽然存入链表L中，
但是链表数据不能完全被显示*/
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    struct ListNode *L;
    L=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *head;
    head=L;

    while(l1&&l2)
    {
        if(l1->val<=l2->val) 
        {
            head->next=l1;
            l1=l1->next;
        }
        else
        {
            head->next=l2;
            l2=l2->next;
        }
        head=head->next;
    }
    if(l1) head->next=l1;
    else if(l2) head->next=l2;
    return L->next;
}
