
int is_valid(char **argv, int i)
{
    if (!(isdigit(argv[i])) || (argv[i] == '' && argv[i + 1] == ''))
    {
        return 0;
    }
}