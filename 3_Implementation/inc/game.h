/** 
* @file Mr_Bean's_Wire_Loop_Game.h
* A CLI Wire Loop Game designed inspired from Mr.Bean's Comedy series.
*
*/
#ifndef __GAME_H__
#define __GAME_H__

/// These are the different game playfield patterns for the levels easy, medium and hard.
extern char pattern1[7][25],pattern2[20][50],pattern3[20][100];
/// This is a global variable to indicate the current level of user.
extern int Level;
/// These are the global control variables that are used for traversal of up and down probes in the game.
extern char up_left, up_down, up_up, up_right, down_left, down_down, down_up, down_right;
/// This ia global variable to holds user's game ID.
extern char g_id[50];
/// This is a global variable to hold time taken by user.
extern double time_taken;
/// This is a global variable to indicate whether its valid to run the game.
extern int flag;
/// This is a structure to hold the x,y position variables of the probes 
struct probe_pos{
	int begin_x,begin_y;
	int end_x,end_y;
    int x,y;
};
/// This is a structure to hold the height and width of the pattern as well as the position of probes in that playfield pattern. 
typedef struct{
	int height,width;
	struct probe_pos upprobe,downprobe;
}patterns;

void change_setting(void);///< A function that guide you through the level and control setting change of the game.
/**
 * @brief A function to append the score ie.,time taken to finish the game in log.txt file.
 * 
 * @param[in] status 
 * @param[in] time_taken 
 */
void score_log(int status,double time_taken);
void show_info(void);//< A function to display the rules and how to play the game. 
void show_menu(void);//< A function to dispaly menu.
/**
 * @brief A function to display the gaming interface.
 * 
 * @param[in] level 
 */
void start_game(int level);
/// Array of function pointers to display diffrent playfield patterns.
void (*print_pattern[3])(void);
/// A function to clear console in linux, windows, unix and apple OS.
void clear();
#endif /* #define __GAME_H__ */