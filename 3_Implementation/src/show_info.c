#include"game.h"
#include<stdio.h>
#include<conio.h>
char l_modes[4][8]={{'\0'},{"Easy"},{"Medium"},{"Hard"}};
//char up_left = 'q',up_down='w',up_up='e',up_right='r';
//char down_left = 'h',down_down='j',down_up='k',down_right='l';
void show_info(void){
    clear();
    printf("\nWelcome %s\n",g_id);
    printf("You are in level: %s",l_modes[Level]);
    printf("\nRULES\n");
    printf("\n  *'|' in the game you see is the probe. There are two probes in the game. \n");
    printf("\n  *One is called up probe, the other is called down probe.                 \n");
    printf("\n  *These probes can be traversed in four directions up down left or right.  \n");
    printf("\n  *Your task is to move each of these probe without touching '#' in the game.\n");
    printf("\n  *Lesser the time you finish the game more is your hand-eye coordination\n");
    printf("\n  *Enter 'm' in any case to go back to menu screen\n");
    printf("\nnote: Refer log.txt file for time taken information                       \n");
    printf("\nCONTROLS\n");
    printf("\nUP PROBE CONTROL :- LEFT: '%c' DOWN: '%c' UP: '%c' RIGHT: '%c'\n",up_left,up_down,up_up,up_right);
    printf("\nDOWN PROBE CONTROL :- LEFT: '%c' DOWN: '%c' UP: '%c' RIGHT: '%c'\n",down_left,down_down,down_up,down_right);

    printf("\nTo menu screen press 'm' \n");
    if(getchar() == 'm')
        show_menu();
}
    