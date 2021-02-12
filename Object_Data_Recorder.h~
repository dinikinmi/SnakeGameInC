#ifndef _OBJECT_DATA_RECORDER_H
#define _OBJECT_DATA_RECORDER_H
#include "E:\g\g\self business\文科JAVA\example program dog snake\Global_Define.h"
#include "E:\g\g\self business\文科JAVA\dog_snake\dog_snake\Global_Value.h"

#include "E:\g\g\self business\文科JAVA\dog_snake\dog_snake\Dog_Manager.h"
#include "E:\g\g\self business\文科JAVA\dog_snake\dog_snake\Brick_Manager.h"
#include "E:\g\g\self business\文科JAVA\dog_snake\dog_snake\Food_Manager.h"
#include "E:\g\g\self business\文科JAVA\dog_snake\dog_snake\Object_Data_Recorder.h"
#include "E:\g\g\self business\文科JAVA\dog_snake\dog_snake\Data_Proccessor.h"






struct Object
{enum Class source_object_class;
struct Object * latter;
struct Object * formor;
void * source_object_pointer;
};


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

struct Object * make_object_link();//return link head object;
struct Object * get_last_object_pointer();


struct Object_Data_Recorder
{void (*update_screen_parttern_record)();
 void (*delete_an_object)(void * deleted_object_pointer); 
 void (*delete_a_class)(enum Class);
 //enum Boolean (*check_class_exist)(int,int,enum Class);
 enum Boolean (*whether_class_exist)(enum Class);
 void (*clean_screen_parttern_record)();              
 void (*add_new_object)(void *,enum Class source_object_class);
 struct Object * (*make_object_link)();
 struct Object * (*get_last_object_pointer)();
 enum Boolean (*class_cornfirm_by_xy)(int, int, enum Class);
 enum Class (*get_class_by_xy)(int,int);
};

struct Object_Data_Recorder make_object_data_recorder();




#endif


