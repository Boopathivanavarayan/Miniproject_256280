#ifndef __GAME_H__
#define __GAME_H__

extern char pattern1[7][25],pattern2[20][50],pattern3[20][100];
extern int Level;
extern char up_left, up_down, up_up, up_right, down_left, down_down, down_up, down_right;
extern char g_id[50];
extern double time_taken;
extern int flag;

struct probe_pos{
	int begin_x,begin_y;
	int end_x,end_y;
    int x,y;
};
typedef struct{
	int height,width;
	struct probe_pos upprobe,downprobe;
}patterns;

void change_setting(void);
void score_log(int status,double time_taken);
void show_info(void);
void show_menu(void);
void start_game(int level);
void (*print_pattern[3])(void);
void clear();
#endif