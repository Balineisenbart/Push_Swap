
void sa(t_node **head_a, t_node **tail_a) //call only when !NULL && !(*head_a)->next = *head_a
{
    t_node *temp = *head_a; //save node1

    *head_a = (*head_a)->next; //make node2 head
    temp->next = (*head_a)->next; //connect new node1 with node3, node1 effectively becomes node2
    (*head_a)->next->prev = temp; //and node3 with node1
    (*head_a)->next = temp; //connect new node1 to new node2
    temp->prev = *head_a; //connect back: new node2 to new node1

    *tail_a->next = *head_a;
    *head_a->prev = *tail_a;
}

void sb(, t_node **head_b, t_node **tail_b)
{
    t_node *temp = *head_b;

    *head_b = (*head_b)->next;
    temp->next = (*head_b)->next;
    (*head_b)->next->prev = temp;
    (*head_b)->next = temp;
    temp->prev = *head_b;


    *tail_b->next = *head_b;
    *head_b->prev = *tail_b;
}