/*21 合并链表*/
 
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
