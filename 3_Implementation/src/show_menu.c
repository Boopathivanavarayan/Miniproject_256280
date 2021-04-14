#include"game.h"
#include<stdio.h>
#include<stdlib.h>
void show_menu(){
    int *menu;
    flag = 1;
    clear();
    printf("\n1)Show game rules and controls\n");
    printf("\n2)Start\n");
    printf("\n3)Change Setting\n");
    printf("\n4)Exit\n");
    printf("\nEnter 1 or 2 or 3 or 4 and Press Enter\n");
    menu = (int*)malloc(sizeof(int));
    scanf("%d",menu);
    enum sh_menu{sh_info=1,srt,ch_set,ext};
    switch(*menu){
        case sh_info : show_info();
        break;
        case srt: start_game(Level);
        break;
        case ch_set: change_setting();
        break;
        case ext: exit(0);
    }
    free(menu);
}