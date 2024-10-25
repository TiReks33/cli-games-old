#ifndef Header_h
#define Header_h
void show_rules(void);
void init_show(char (*p_num)[9][3]);

void play_show(char (*p_num)[9][3]);
void play_chose(int*p_s, char (*p_num)[9][3]);
void play_clear(int*p_s, char (*p_num)[9][3]);

void side(int*p_s);

void move(char (*p_num)[9][3],int*p_s,int*red_score,int*blue_score);

void attack(char (*p_num)[9][3],int*p_s,int*red_score,int*blue_score,int*p_rkill,int*p_bkill);

void end_game(char a, char (*p_num)[9][3]);

 //prototypes (declaration) of funcs
#endif //Header
