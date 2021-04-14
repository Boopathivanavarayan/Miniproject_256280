#include"game.h"
#include<stdio.h>
#include<conio.h>
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
        printf("\nTo menu screen press 'm' \n");
        if(getch() == 'm')
            show_menu();   
    }
    if(setting==2){
        printf("\nEnter your comfortable control keys\n");
        printf("\nEnter left control key for up_probe: \n");
        up_left = getch();
        printf("%c",up_left);
        printf("\nEnter down cntrol key for up_probe: \n");
        up_down = getch();
        printf("%c",up_down);
        printf("\nEnter up cntrol key for up_probe: \n");
        up_up = getch();
        printf("%c",up_up);
        printf("\nEnter right cntrol key for up_probe: \n");
        up_right = getch();
        printf("%c",up_right);
        printf("\nEnter left cntrol key for down_probe: \n");
        down_left = getch();
        printf("%c",down_left); 
        printf("\nEnter down cntrol key for down_probe: \n");
        down_down = getch();
        printf("%c",down_down);
        printf("\nEnter up cntrol key for down_probe: \n");
        down_up = getch();
        printf("%c",down_up);
        printf("\nEnter right cntrol key for down_probe: \n");
        down_right = getch();
        printf("%c",down_right);
        printf("\nTo menu screen press 'm' \n");
        if(getch() == 'm')
            show_menu();
    }
    
}
