#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<mem.h>
#include"game.h"


int main(){
    clear();
    printf("\n          WELCOME          \n");
    printf("\n            TO          \n");
    printf("\n         Mr.BEAN'S        \n");
    printf("\n       WIRE LOOP GAME         \n");
   
    printf("\nEnter game ID (without space)\n");

    scanf("%s",g_id);

    show_info();

    printf("\nPress 'c' to continue\n");

    if(getch() =='c'){
             show_menu();
        }
  
}

