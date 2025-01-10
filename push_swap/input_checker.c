
int is_valid(char *numbers)
{
    int i;
    int flag;

    i = 0;
    sign = 0;
    if (number[0] == '-' || number[0] == '+')
        i++;
    while (numbers != '\0')
    {
        if (number[i] == '-' || number[i] == '+')
            sign = 1;
        if (numbers[i] <= '0' || numbers[i] >= '9' && sign != 0 )
            return 0;
        i++;
    }
    return 1;
}

int has_duplicates(t_node *stack, int value)
{
    while (stack)
    {
        if (stack->value = value)
            return 1;
        stack = stack->next;
    }
   return 0; 
}