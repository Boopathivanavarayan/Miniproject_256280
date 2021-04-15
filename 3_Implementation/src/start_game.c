#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<mem.h>
#include"game.h"


//Structure array
//easy
patterns p[3] = {    {.height=7,.width=25,.upprobe.begin_x=0,.upprobe.begin_y=1,.downprobe.begin_x=0,.downprobe.begin_y=3,
.upprobe.end_x=24,.upprobe.end_y=4,.downprobe.end_x=24,.downprobe.end_y=6,.upprobe.x=0,.upprobe.y=0,.downprobe.x=0,.downprobe.y=0},
//medium
{.height=20,.width=50,.upprobe.begin_x=0,.upprobe.begin_y=1,.downprobe.begin_x=0,.downprobe.begin_y=3,
.upprobe.end_x=49,.upprobe.end_y=13,.downprobe.end_x=49,.downprobe.end_y=15,.upprobe.x=0,.upprobe.y=0,.downprobe.x=0,.downprobe.y=0},
//hard
{.height=20,.width=100,.upprobe.begin_x=0,.upprobe.begin_y=1,.downprobe.begin_x=0,.downprobe.begin_y=3,
.upprobe.end_x=99,.upprobe.end_y=16,.downprobe.end_x=99,.downprobe.end_y=18,.upprobe.x=0,.upprobe.y=0,.downprobe.x=0,.downprobe.y=0}   };

//Default Controls
//char up_left = 'q', up_down='w', up_up='e', up_right='r';
//char down_left = 'h', down_down='j', down_up='k', down_right='l';

//variable to store system time
time_t t1;

//global variables g_id -> game_id of user
char g_id[50] = "NoONE";
double time_taken;

char m='q';
//up-> up probe dp->down probe
char up_ctrl;
char dp_ctrl;
int mx,my,nx,ny;
enum state{incomplete,complete};

//functions to print different patterns
void easy(void){
            printf("\n");
            for(int i=0;i<p[0].height;i++){
                for(int j=0;j<p[0].width;j++){
                    printf("%c",pattern1[i][j]);
                }
                printf("\n");
            }
}
void medium(void){
            printf("\n");
            for(int i=0;i<p[1].height;i++){
                for(int j=0;j<p[1].width;j++){
                    printf("%c",pattern2[i][j]);
                }
                printf("\n");
            }
}
void hard(void){
            printf("\n");
            for(int i=0;i<p[2].height;i++){
                for(int j=0;j<p[2].width;j++){
                    printf("%c",pattern3[i][j]);
                }
                printf("\n");
            }
}
//function pointer 
void (*print_pattern[3])(void) = {easy,medium,hard};
void set_probe_begning(int level);
void start_game(int level){
     //start to record time
        t1 = clock();
        set_probe_begning(level);
        while(flag == 1){
            clear();
            p[level-1].upprobe.x = p[level-1].upprobe.y = p[level-1].downprobe.x = p[level-1].downprobe.y =0; 
            m = 'q';
            print_pattern[level-1]();
            // Get up probe down probe controls from user
            printf("Press m twice to go back to menu");
            printf("\nEnter up probe control \n");
            printf("\nUP PROBE CONTROL :- LEFT: '%c' DOWN: '%c' UP: '%c' RIGHT: '%c'\n",up_left,up_down,up_up,up_right);
            up_ctrl = getchar();
            printf("\n %c \n",up_ctrl);
            m = up_ctrl;
            printf("\nEnter down probe control \n");
            printf("\nDOWN PROBE CONTROL :- LEFT: '%c' DOWN: '%c' UP: '%c' RIGHT: '%c'\n",down_left,down_down,down_up,down_right);
            dp_ctrl = getchar();
            printf("\n %c \n",dp_ctrl);
            m = dp_ctrl;

            if(m == 'm')
                show_menu();
        
            p[level-1].upprobe.x = p[level-1].upprobe.y = p[level-1].downprobe.x = p[level-1].downprobe.y =0; 
            // Check for left, right, down or up control and update variables accordingly.
            if(up_ctrl == up_left)
                p[level-1].upprobe.x = -1;
            else if(up_ctrl == up_down)
                p[level-1].upprobe.y = 1;
            else if(up_ctrl == up_up)
                p[level-1].upprobe.y = -1;
            else if(up_ctrl == up_right)
                p[level-1].upprobe.x = 1;
            else{
                 printf("Invalid move");
                 set_probe_begning(level);
                 continue;
            }
               
            if(dp_ctrl == down_left)
                p[level-1].downprobe.x = -1;
            else if(dp_ctrl == down_down)
                p[level-1].downprobe.y = 1;
            else if(dp_ctrl == down_up)
                p[level-1].downprobe.y = -1;
            else if(dp_ctrl == down_right)
                p[level-1].downprobe.x = 1;
            else{
                 printf("Invalid move");
                 set_probe_begning(level);
                 continue;
            }
                        
          
            //calculate new positions of the probes m-> up probe n-> down probe
            mx = p[level-1].upprobe.begin_x + p[level-1].upprobe.x;
            my = p[level-1].upprobe.begin_y + p[level-1].upprobe.y;
            nx = p[level-1].downprobe.begin_x + p[level-1].downprobe.x;
            ny = p[level-1].downprobe.begin_y + p[level-1].downprobe.y;
 
            //Check whether new positions are valid
            if((mx >=0 && mx < p[level-1].width) && (my >= 0 && my < p[level-1].height) &&
                    (nx >=0 && nx < p[level-1].width) && (ny >= 0 && ny < p[level-1].height)){
                //In case probe position and '#' match end the game.
                if(level == 1 && (pattern1[ny][nx] =='#'|| pattern1[my][mx] =='#')){

                        clear();
                        printf("\n     Don't Worry! Better Luck Next Time\n");
                        t1 = clock()-t1;
                        time_taken = (double)t1/CLOCKS_PER_SEC;
                        score_log(incomplete,time_taken);
                        printf("\nPress'r' to restart\n");
                        if(getchar()=='r')
                            start_game(Level);
                }

                else if(level == 2 && (pattern2[ny][nx]=='#'|| pattern2[my][mx]=='#')){
                        
                        clear();
                        printf("\n     Don't Worry! Better Luck Next Time\n");
                        t1 = clock()-t1;
                        time_taken = (double)t1/CLOCKS_PER_SEC;
                        score_log(incomplete,time_taken);
                        printf("\nPress'r' to restart\n");
                        if(getchar()=='r')
                            start_game(Level);
                }
               
                else if(level == 3 && (pattern3[ny][nx]=='#'|| pattern3[my][mx]=='#')){
                       
                        clear();
                        printf("\n     Don't Worry! Better Luck Next Time\n");
                        t1 = clock()-t1;
                        time_taken = (double)t1/CLOCKS_PER_SEC;
                        score_log(incomplete,time_taken);
                        printf("\nPress'r' to restart\n");
                        if(getchar()=='r')
                            start_game(Level);
                }
                // Check whether probes are apart. 
                if(abs(ny-my) > 3){
                    clear();
                    printf("\n   ALERT: Probes are far apart\n");
                    printf("\nPress'r' to restart\n");
                    if(getchar()=='r')
                        start_game(Level);
                }
                if(abs(nx-mx) > 3){
                    clear();
                    printf("\n   ALERT: Probes are far apart\n");
                    printf("\nPress'r' to restart\n");
                    if(getchar()=='r')
                        start_game(Level);
                }
                //Check whether user reached the end of the game.
                if(ny >= p[level-1].downprobe.end_y && nx >= p[level-1].downprobe.end_x && 
                        my >= p[level-1].upprobe.end_y && mx >= p[level-1].upprobe.end_x){
                            clear();
                            t1 = clock()-t1;
                            time_taken = (double)t1/CLOCKS_PER_SEC;
                            printf("\n    BRAVOO! YOU WON!!!\n");
                            printf("\n You finished in %lf seconds\n",time_taken);
                            score_log(complete,time_taken);
                            printf("\n Press'x' to exit\n");
                            if(getchar()=='x')
                                exit(0);
                }
                else{
                    // delete current position of the probes.
                    if(level == 1){
                        pattern1[p[level-1].upprobe.begin_y][p[level-1].upprobe.begin_x] = '-';
                        pattern1[p[level-1].downprobe.begin_y][p[level-1].downprobe.begin_x] = '-';
                    }
                    else if(level == 2){
                        pattern2[p[level-1].upprobe.begin_y][p[level-1].upprobe.begin_x] = '-';
                        pattern2[p[level-1].downprobe.begin_y][p[level-1].downprobe.begin_x] = '-';
                    }
                    else if(level == 3){
                        pattern3[p[level-1].upprobe.begin_y][p[level-1].upprobe.begin_x] = '-';
                        pattern3[p[level-1].downprobe.begin_y][p[level-1].downprobe.begin_x] = '-';
                    }   
                    // update current position
                    p[level-1].upprobe.begin_x += p[level-1].upprobe.x;
                    p[level-1].upprobe.begin_y += p[level-1].upprobe.y;
                    p[level-1].downprobe.begin_x += p[level-1].downprobe.x;
                    p[level-1].downprobe.begin_y += p[level-1].downprobe.y;

                    // move the probes
                    if(level == 1){
                        pattern1[p[level-1].upprobe.begin_y][p[level-1].upprobe.begin_x] = '|';
                        pattern1[p[level-1].downprobe.begin_y][p[level-1].downprobe.begin_x] = '|';
                    }
                    else if(level == 2){
                        pattern2[p[level-1].upprobe.begin_y][p[level-1].upprobe.begin_x] = '|';
                        pattern2[p[level-1].downprobe.begin_y][p[level-1].downprobe.begin_x] = '|';
                    }
                     else if(level == 3){
                        pattern3[p[level-1].upprobe.begin_y][p[level-1].upprobe.begin_x] = '|';
                        pattern3[p[level-1].downprobe.begin_y][p[level-1].downprobe.begin_x] = '|';
                    }
                }
               
            }
            else{
                printf("Invalid Move");
                set_probe_begning(level);
                continue;
            } 
           
        }
        //set_probe_begning(Level);
        show_menu();
}
void set_probe_begning(int level){
    if(level == 1){
        if(pattern1[p[level-1].upprobe.begin_y][p[level-1].upprobe.begin_x] == '#')
            pattern1[p[level-1].upprobe.begin_y][p[level-1].upprobe.begin_x] = '#';
        else
            pattern1[p[level-1].upprobe.begin_y][p[level-1].upprobe.begin_x] = '-';
        
        if( pattern1[p[level-1].downprobe.begin_y][p[level-1].downprobe.begin_x] == '#')
             pattern1[p[level-1].downprobe.begin_y][p[level-1].downprobe.begin_x] = '#';
        else
            pattern1[p[level-1].downprobe.begin_y][p[level-1].downprobe.begin_x]= '-';

        pattern1[1][0] = '|';
        pattern1[3][0] = '|';
    }
    else if(level == 2){
        if(pattern2[p[level-1].upprobe.begin_y][p[level-1].upprobe.begin_x] == '#')
            pattern2[p[level-1].upprobe.begin_y][p[level-1].upprobe.begin_x] = '#';
        else
            pattern2[p[level-1].upprobe.begin_y][p[level-1].upprobe.begin_x] = '-';
        
        if( pattern2[p[level-1].downprobe.begin_y][p[level-1].downprobe.begin_x] == '#')
             pattern2[p[level-1].downprobe.begin_y][p[level-1].downprobe.begin_x] = '#';
        else
            pattern2[p[level-1].downprobe.begin_y][p[level-1].downprobe.begin_x]= '-';

        pattern2[1][0] = '|';
        pattern2[3][0] = '|';
    }
        else if(level == 3){
            if( pattern3[p[level-1].upprobe.begin_y][p[level-1].upprobe.begin_x] == '#')
                 pattern3[p[level-1].upprobe.begin_y][p[level-1].upprobe.begin_x] = '#';
            else
                pattern3[p[level-1].upprobe.begin_y][p[level-1].upprobe.begin_x] = '-';
        
            if(  pattern3[p[level-1].downprobe.begin_y][p[level-1].downprobe.begin_x] == '#')
                 pattern3[p[level-1].downprobe.begin_y][p[level-1].downprobe.begin_x]  = '#';
            else
                pattern3[p[level-1].downprobe.begin_y][p[level-1].downprobe.begin_x] = '-';

        pattern3[1][0] = '|';
        pattern3[3][0] = '|';
    }

}