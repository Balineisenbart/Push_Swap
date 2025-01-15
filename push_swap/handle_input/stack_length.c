
int stack_length(t_node *head)
{
    t_node *temp = head;
    int     i;

    i = 0;
    while(temp->next != head)
    {
        i++;
        temp = temp->next;
    }
}