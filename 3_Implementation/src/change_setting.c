#include"game.h"
#include<stdio.h>
#include<stdlib.h>
int Level = 1;
char up_left = 'q',up_down='w',up_up='e',up_right='r';
char down_left = 'h',down_down='j',down_up='k',down_right='l';
int flag = 0;
void change_setting(void){
    int setting;
    clear();
    printf("\n1)Level Setting\n");
    printf("\n2)Control Setting\n");
    printf("\n Enter 1 or 2\n");
    scanf("%d",&setting);
    clear();
    if(setting==1){
        printf("\n1)Easy\n");
        printf("\n2)Medium\n");
        printf("\n3)Hard\n");
        printf("\n Enter 1 or 2 or 3\n");
        scanf("%d",&Level);
        printf("\nPress 'm' for menu\n");
        char *menu = (char*)malloc(sizeof(char));
        scanf("%s",menu);
        if(*menu == 'm'){
            free(menu);
            show_menu();
        }
    }
    if(setting==2){

        char *ctrl = (char*)malloc(sizeof(char));
        printf("\nEnter your comfortable control keys\n");
        printf("\nEnter left control key for up_probe and Enter: \n");
        scanf("%s",ctrl);
        up_left = *ctrl;

        printf("\nEnter down control key for up_probe and Enter: \n");
        scanf("%s",ctrl);
        up_down = *ctrl;

        printf("\nEnter up control key for up_probe and Enter: \n");
        scanf("%s",ctrl);
        up_up = *ctrl;

        printf("\nEnter right control key for up_probe and Enter: \n");
        scanf("%s",ctrl);
        up_right = *ctrl;

        printf("\nEnter left control key for down_probe and Enter: \n");
        scanf("%s",ctrl);
        down_left = *ctrl;

        printf("\nEnter down control key for down_probe and Enter: \n");
        scanf("%s",ctrl);
        down_down = *ctrl;

        printf("\nEnter up control key for down_probe and Enter: \n");
        scanf("%s",ctrl);
        down_up = *ctrl;

        printf("\nEnter right control key for down_probe and Enter: \n");
        scanf("%s",ctrl);
        down_right = *ctrl;

        free(ctrl);
        printf("\nPress 'm' for menu\n");
        char *menu = (char*)malloc(sizeof(char));
        scanf("%s",menu);
        if(*menu == 'm'){
            free(menu);
            show_menu();
        }
    }
    
}
