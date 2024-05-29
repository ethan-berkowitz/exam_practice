#include <unistd.h>

int main(int argc, char *argv[])
{
    int i;
    int flag;

    flag = 0;
    if (argc == 2)
    {
        i = 0;
        while (argv[1][i] == 9 || argv[1][i] == 32)
            i++;
        while (argv[1][i] && argv[1][i] != 9 && argv[1][i] != 32)
            i++;
        while (argv[1][i])
        {
            while (argv[1][i] == 9 || argv[1][i] == 32)
                i++;
            while (argv[1][i] && argv[1][i] != 9 && argv[1][i] != 32)
            {
                write(1, &argv[1][i], 1);
                flag = 1;
                i++;
            }
            if (argv[1][i])
                write(1, " ", 1);
        }
        if (flag == 1)
            write(1, " ", 1);
        i = 0;
        while (argv[1][i] == 9 || argv[1][i] == 32)
            i++;
        while (argv[1][i] && argv[1][i] != 9 && argv[1][i] != 32)
        {
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0); // <------------
}
