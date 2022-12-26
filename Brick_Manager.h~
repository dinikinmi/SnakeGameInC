#ifndef BRICK_MANAGER_H
#define BRICK_MANAGER_H

#include "Data_Proccessor.h"
#include "Global_Define.h"
#include "Global_Value.h"



struct Brick
{int x;
 int y;
 int hardness;
};



void make_a_wall
(int x_start,int y_start,int x_end,int y_end);

void make_4_wall();
void handle_hitting_event(struct Brick * hitting_brick); 

struct Brick * make_a_brick();

struct Brick_Manager
{void (*make_a_wall)(int,int,int,int);
 void (*make_4_wall)();
 struct Brick * (*make_a_brick)(int,int,int); 
 struct Brick * (*make_a_random_brick)();
 void (*handle_hitting_event)(struct Brick *);	
};

struct Brick_Manager make_brick_manager();




#endif


