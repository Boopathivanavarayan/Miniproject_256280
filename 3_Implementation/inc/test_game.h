
#ifndef __TEST_GAME_H__
#define __TEST_GAME_H__

extern char pattern1[7][25],pattern2[20][50],pattern3[20][100];

extern int Level;

extern char up_left, up_down, up_up, up_right, down_left, down_down, down_up, down_right;
 
struct probe_pos{
	int begin_x,begin_y;
	int end_x,end_y;
    int x,y;
};

typedef struct{
	int height,width;
	struct probe_pos upprobe,downprobe;
}patterns;

int* test_move(int level, char up_ctrl, char dp_ctrl);

#endif /* #define __GAME_H__ */