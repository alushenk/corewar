#include "corewar.h"

void ft_print_player(t_players *player)
{
    unsigned int kk;


    printf("[%s]\n", player->name);
    printf("[%s]\n", player->comment);
    printf("[%d]\n", player->size);

    kk = 0;
    printf("[");
    while (kk < player->size)
    {
        printf("%.2x ", player->code[kk]);
        kk++;
    }
    printf("]\n");
    printf("---------------------------------------------------------------------------------------------------\n");
}


void    ft_print_map(t_vm *vm, t_players **players)
{
    unsigned int     i;
    int     flag;
    int     k;

    k = 0;
    flag = 0;
    i = 0;

    while (i < MEM_SIZE)
    {
        k = 0;
        flag = 0;
        while (k < vm->players_count)
        {
            if (i >= vm->players[k].pc && i < vm->players[k].pc + players[k]->size) {
                flag = 1;
            }
            k++;
        }
        if (flag)
        {
            printf(ANSI_COLOR_GREEN "%.2x " ANSI_COLOR_RESET, vm->arena[i]);
        } else
        {
            printf( "%.2x ", vm->arena[i]);
        }
        flag = 0;

        if ((i + 1) % 64 == 0 && i != 0)
        {
            printf("\n");
        }
         i++;
    }
    printf("%d\n", k);
//    printf("lol\n");
}
