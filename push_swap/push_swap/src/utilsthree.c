#include "../include/push_swap.h"



static int  repeated(int nb, char **argv, int i)
{
    i++;
    while(argv[i])
    {
        if (ft_atoi(argv[i]) == nb)
            return (1);
        i++;
    }
    return (0);
}

static int ft_isnum(char *nb)
{
    int i;
    i = 0;

    if (nb[0] == '-')
        i++;
    while (nb[i])
    {
        if (!ft_isdigit(nb[i]))
            return (0);
        i++;
    }
    return (1);
}

void checkargs(int argc, char **argv)
{
    int i;
    long tmp;
    char **args;

    i = 0;
    if (argc == 2)
        args = ft_split(argv[1], ' ');
    else
    {
        i = 1;
        args = argv;
    }
    while (args[i])
    {
        tmp = ft_atoi(args[i]);
        if (!ft_isnum(args[i]))
            ft_puterror("Error");
        if (repeated(tmp, args, i))
            ft_puterror("Error");
        if (tmp < -2147483648 || tmp > 2147483647)
            ft_puterror("Error");
        i++;
    }

    if (argc == 2)
        free_strings (args);
}
