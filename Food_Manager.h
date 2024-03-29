#ifndef _FOOD_MANAGER_H
#define _FOOD_MANAGER_H

#include "Object_Data_Recorder.h"
#include "Global_Define.h"
#include "Global_Value.h"

enum Food_Type 
{hp,mp,time_slow,score};

struct Food
{int x,y;
 enum Food_Type type;
 };


char get_food_parttern(struct Food * food); 

void make_a_random_food();
void make_a_food(int x,int y,enum Food_Type type);
void eating_event_handle(struct Food * eaten_food_pointer);

struct Food_Manager
{void (*make_a_random_food)();
 void (*make_a_food)(int,int,enum Food_Type);
 void (*eating_event_handle)(struct Food *);
 char (*get_food_parttern)(struct Food *);
};


struct Food_Manager make_food_manager();

#endif
