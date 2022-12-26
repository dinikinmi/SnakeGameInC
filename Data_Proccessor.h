#ifndef _Data_Proccessor_H
#define _Data_Proccessor_H
#include "Global_Define.h"
#include "Global_Value.h"
#include "Dog_Manager.h"
#include "Food_Manager.h"
#include "Brick_Manager.h"
#include "Object_Data_Recorder.h"

 


/*void free_memory(void * pointer);*/
long long current_timestamp();

enum SongName {hit_brick,eat_score,eat_Majc,eat_HP,
             game_over,eat_timmer,
			 magic_slow_down,
			 magic_heal,
			 magic_u_turn,
			 magic_teleport_start,
			 magic_teleport_finish,
			 magic_clean_start,
			 magic_clean_finish,
			 magic_fail};

void draw_point(COORD coord);

void setPartternColor(char parttern);

void calculate_next_xy_by_vetor
  (int x_start,int y_start,
   int x_end,int y_end,
   int * new_x,int * new_y
  );
  
void play_music(enum SongName songNumber);  
void draw_screen();
void draw_screen_area(int x_limit,int y_limit);
void printInfo();
void clean_announcement();
void setCursorInDefaultHandle(int x,int y);


void handle_event();
enum Boolean whether_hitting_brick(struct Brick * brick);
enum Boolean whether_hitting_dog(struct Dog * dog);
enum Boolean whether_eating_food(struct Food * food);
  

void clean_and_free_ram(void * pointer,int x,int y); 

struct Data_Proccessor
{void (*draw_screen)();
 void (*free_memory)(void *);
 void (*draw_screen_area)(int,int);
 void (*calculate_next_xy_by_vector)
 (int,int,int,int,int *,int *);	
 void (*handle_event)();
 void (*clean_and_free_ram)(void *,int,int);
 void (*draw_point)(COORD);
 void (*clean_announcement)();
 void (*printInfo)();
 void (*play_music)(enum SongName);
 void (*setCursorInDefaultHandle)(int,int); 
 void (*setPartternColor)(char);
 long long (*current_timestamp)();
};	




struct Data_Proccessor make_data_proccessor(); 

#endif
