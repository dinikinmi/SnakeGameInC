#ifndef _DOG_MANAGER_H
#define _DOG_MANAGER_H
#include "Global_Define.h"
#include "Global_Value.h"
#include "Object_Data_Recorder.h"

#include <unistd.h>
#include <windows.h>

enum Dog_Role {head_dog,tail_dog,middle_dog}; 
enum Lengthen_Direction {formor,latter}; 
enum Move_Direction {up=1,down=-1,left=2,right=-2,stay=0};

enum Lengthen_Direction get_lengthen_direction();

void handle_user_input();
void move_dog_queue();
void queue_u_turn();

struct Dog * get_next_dog_by_lengthen_direction
      (struct Dog* now_operating_dog_pointer);
      
struct Dog * make_a_new_dog(int x,int y);
struct Dog * get_tail_dog_pointer();
struct Dog * make_a_dog_queue(int start_x,int start_y,int end_x,int end_y);

struct Dog * get_next_dog_pointer
   (struct Dog * now_checking_dog,
   enum Lengthen_Direction lengthen_direction); 

char get_dog_parttern(struct Dog *);

enum Boolean wait_user_confirm(char * message);
void majic_u_turn();
void majic_teleport();
void majic_slow_down();
void majic_clean_all_brick();
void majic_heal();
void majic_accelerate(); 
void magic_fresh();

void drawDogQueue();
void drawTail(struct Dog * tail_dog);

struct Dog * add_new_dog_to_queue_tail();


struct Dog
{int x;int y;
enum Dog_Role role;
struct Dog * formor;
struct Dog * latter;
};



struct Dog_Manager
{void  (*move_dog_queue)(); 
 void  (*handle_user_input)();
 void  (*queue_u_turn)();
 void (*majic_u_turn)();
 void (*majic_teleport)();
 void (*majic_slow_down)();
 void (*majic_clean_all_brick)();
 void (*majic_heal)();
 void (*majic_accelerate)();
 void (*magic_fresh)(); 
 void (*drawDogQueue)();
 void (*drawTail)(struct Dog * );

 enum Boolean (*wait_user_confirm)(char * message);
 
 struct Dog * (*get_tail_dog_pointer)();
 struct Dog * (*make_a_dog_queue)(int,int,int,int); 
 struct Dog * (*add_new_dog_to_queue_tail)();
 struct Dog * (*make_a_new_dog)(int,int);
 enum Lengthen_Direction (*get_lengthen_direction)(); 
 struct Dog * (*get_next_dog_pointer)(struct Dog*,enum Lengthen_Direction); 
 struct Dog * (*get_next_dog_by_lengthen_direction)(struct Dog *); 
 char (*get_dog_parttern)(struct Dog *);

};

struct Dog_Manager make_dog_manager();

#endif
