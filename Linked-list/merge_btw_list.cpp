ListNode *fast = list1;
ListNode *slow = NULL;
ListNode *temp = list2;
else
{
    while (fast->val != a)
    {
        slow = fast;
        fast = fast->next;
    }
    while (fast->val != b)
    {
        fast = fast->next;
    }
    if (fast->next != NULL)
    {
        fast = fast->next;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    slow->next = list2;
    temp->next = fast;
}
return list1;