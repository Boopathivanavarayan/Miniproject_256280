#include"game.h"
#include<stdio.h>
#include<stdlib.h>

void score_log(int status,double time_taken){
    FILE *fptr;
    fptr = fopen("log.txt","a");
    char l[3][10] = {{"Easy"},{"Medium"},{"Hard"}};
    if(fptr == NULL){
        printf("Error opening File");
    }

    else{
        
        if(status)
            fprintf(fptr,"\n  %s          %s          %s          %fs \n",g_id,"Complete",l[Level-1],time_taken);
        else
           fprintf(fptr,"\n  %s          %s          %s          %fs \n",g_id,"Incomplete",l[Level-1],time_taken);

    }
    fclose(fptr);
}