#ifndef _Data_Proccessor_H
#define _Data_Proccessor_H
#include "Global_Define.h"
#include "Global_Value.h"
#include "Dog_Manager.h"
#include "Food_Manager.h"
#include "Brick_Manager.h"
#include "Object_Data_Recorder.h"

 


//void free_memory(void * pointer);
void calculate_next_xy_by_vetor
  (int x_start,int y_start,
  int x_end,int y_end,
  int * new_x,int * new_y);
void draw_screen();

void handle_event();
enum Boolean whether_hitting_brick(struct Brick * brick);
enum Boolean whether_hitting_dog(struct Dog * dog);
enum Boolean whether_eating_food(struct Food * food);
 


void clean_and_free_ram(void * pointer); 

struct Data_Proccessor
{void (*draw_screen)();
 void (*free_memory)(void *);
 void (*calculate_next_xy_by_vector)
 (int,int,int,int,int *,int *);	
 void (*handle_event)();
 void (*clean_and_free_ram)(void *);
};	




struct Data_Proccessor make_data_proccessor(); 

#endif
