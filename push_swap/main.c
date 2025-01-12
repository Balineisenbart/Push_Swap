

int main(int argc, char **argv)
{
    if (argc > 1 && argv[0] != '\0')
    {
        t_node *head_a = NULL;
        t_node *tail_a = NULL;
        t_node *head_b = NULL;
        t_node *tail_b = NULL;

        parse_input(argc, argv[i], &head_a);
        if (!needs_sorting(head_a))
            return 0;


        //sort 3        if (head_a/b != NULL)
        //sort 5
        //sort more than 5

    }

    return 0;
}