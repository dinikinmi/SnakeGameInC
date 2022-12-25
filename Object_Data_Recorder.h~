#ifndef _OBJECT_DATA_RECORDER_H
#define _OBJECT_DATA_RECORDER_H
#include "Global_Define.h"
#include "Global_Value.h"

#include "Dog_Manager.h"
#include "Brick_Manager.h"
#include "Food_Manager.h"
#include "Object_Data_Recorder.h"
#include "Data_Proccessor.h"






struct Object
{enum Class source_object_class;
struct Object * latter;
struct Object * formor;
void * source_object_pointer;
int x,y;
};

char get_object_parttern(struct Object * objectPointer); 
enum Class get_class_by_xy(int x,int y);
 

enum Boolean class_cornfirm_by_xy(int x, int y, enum Class check_class); 
void delete_a_class(enum Class delete_class);
void clean_screen_parttern_record();
void update_screen_parttern_record();
void delete_an_object(void * deleted_object_pointer);
void delete_object_by_class(enum Class delete_class);
enum Boolean check_class_exist(int x,int y,enum Class class_to_be_checked);	
enum Boolean whether_class_exist(enum Class checking_class);



void add_new_oject
 (void * source_object_pointer,enum Class source_object_class);

struct Object * make_object_link();
/*return link head object;*/
struct Object * get_last_object_pointer();


struct Object_Data_Recorder
{void (*update_screen_parttern_record)();
 void (*delete_an_object)(void * deleted_object_pointer); 
 void (*delete_a_class)(enum Class);
 /*enum Boolean (*check_class_exist)(int,int,enum Class);*/
 enum Boolean (*whether_class_exist)(enum Class);
 void (*clean_screen_parttern_record)();              
 void (*add_new_object)(void *,enum Class source_object_class,int,int);
 void (*update_point_char)(int,int);
 struct Object * (*make_object_link)();
 struct Object * (*get_last_object_pointer)();
 char (*get_object_parttern)(struct Object *);
 enum Boolean (*class_cornfirm_by_xy)(int, int, enum Class);
 enum Class (*get_class_by_xy)(int,int);
};

struct Object_Data_Recorder make_object_data_recorder();




#endif


