
int is_valid(char *numbers)
{
    int i;

    i = 0;
    if (number[0] == '-' || number[0] == '+')
        i++;
    if (numbers[i] == '\0')
        return 0;
    while (numbers[i] != '\0')
    {
        if (numbers[i] < '0' || numbers[i] > '9')
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