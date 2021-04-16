
/** 
* @file TEST_Mr_Bean's_Wire_Loop_Game.h
* Header file specifically used for testing purpose.
*
*/
#ifndef __TEST_GAME_H__
#define __TEST_GAME_H__

/// These are the different game playfield patterns for the levels easy, medium and hard.
extern char pattern1[7][25],pattern2[20][50],pattern3[20][100];
/// This is a global variable to indicate the current level of user.
extern int Level;
/// These are the global control variables that are used for traversal of up and down probes in the game.
extern char up_left, up_down, up_up, up_right, down_left, down_down, down_up, down_right;
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
/// This int array hold values specific for test purpose.
int result[5];
/**
 * @brief This function specifically used to test whether the probes are correctly traversing in the playfield.
 * 
 * @param[in] level 
 * @param[in] up_ctrl 
 * @param[in] dp_ctrl 
 * @return int* pointer to 5 element array that contain test specific values.
 */
int* test_move(int level, char up_ctrl, char dp_ctrl);

#endif /* #define __TEST_GAME_H__ */