#include<stdio.h>
#include<stdlib.h>
#include"test_game.h"


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

//char up_left = 'q',up_down='w',up_up='e',up_right='r';
//char down_left = 'h',down_down='j',down_up='k',down_right='l';

char up_ctrl;
char dp_ctrl;
int mx,my,nx,ny;

//result[0] -> up probe x position
//result[1] -> up probe y position
//result[2] -> down probe x position
//result[3] -> down probe y position
//result[4] -> status indicator
//status 1->fail 2->won 3->in progress 4->index out of range

int result[5];
int* test_move(int level, char up_ctrl, char dp_ctrl){
    
    p[level-1].upprobe.x = p[level-1].upprobe.y = p[level-1].downprobe.x = p[level-1].downprobe.y =0; 
    if(up_ctrl == up_left)
        p[level-1].upprobe.x = -1;
    else if(up_ctrl == up_down)
        p[level-1].upprobe.y = 1;
    else if(up_ctrl == up_up)
        p[level-1].upprobe.y = -1;
    else if(up_ctrl == up_right)
        p[level-1].upprobe.x = 1;
    else{
            return result;
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
           return result;
    }

    mx = p[level-1].upprobe.begin_x + p[level-1].upprobe.x;
    my = p[level-1].upprobe.begin_y + p[level-1].upprobe.y;
    nx = p[level-1].downprobe.begin_x + p[level-1].downprobe.x;
    ny = p[level-1].downprobe.begin_y + p[level-1].downprobe.y;

     if((mx >=0 && mx < p[level-1].width) && (my >= 0 && my < p[level-1].height) &&
         (nx >=0 && nx < p[level-1].width) && (ny >= 0 && ny < p[level-1].height)){
                
            if(level == 1 && (pattern1[ny][nx] =='#'|| pattern1[my][mx] =='#')){
                    result[4] = 1;  
            }

            else if(level == 2 && (pattern2[ny][nx]=='#'|| pattern2[my][mx]=='#')){
                    result[4] = 1;           
            }
               
            else if(level == 3 && (pattern3[ny][nx]=='#'|| pattern3[my][mx]=='#')){
                    result[4] = 1;    
            }
            if(abs(ny-my) > 3){
                result[4] = 1;  
            }

            if(abs(nx-mx) > 3){
                result[4] = 1; 
            }

            if(ny >= p[level-1].downprobe.end_y && nx >= p[level-1].downprobe.end_x && 
                my >= p[level-1].upprobe.end_y && mx >= p[level-1].upprobe.end_x){
                            result[4] = 2;
            }
            else{
                    
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
                //update current position
                p[level-1].upprobe.begin_x += p[level-1].upprobe.x;
                p[level-1].upprobe.begin_y += p[level-1].upprobe.y;
                p[level-1].downprobe.begin_x += p[level-1].downprobe.x;
                p[level-1].downprobe.begin_y += p[level-1].downprobe.y;
                
                result[0] =  p[level-1].upprobe.begin_x;
                
                result[1] =  p[level-1].upprobe.begin_y;
               
                result[2] =  p[level-1].downprobe.begin_x;
               
                result[3] =  p[level-1].downprobe.begin_y;
               
               
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
               result[4] = 4;
        } 
   
    
    return result;
}