
#ifndef GLOBAL_VALUE_H
#define GLOBAL_VALUE_H
#include <stdio.h>
#include "Global_Define.h"
#include <unistd.h>
#include <windows.h>
#include <ctype.h>


struct Dog * g_head_dog_pointer;
struct Object * g_object_link_head_pointer;

struct Dog_Manager g_dog_manager;
struct Food_Manager g_food_manager;
struct Brick_Manager g_brick_manager;
struct Object_Data_Recorder g_object_data_recorder;
struct Data_Proccessor g_data_proccessor;




enum Move_Direction g_move_direction;
enum Boolean {true=1,false=0};
enum Boolean g_whether_food_exist;
enum Boolean g_game_over;

 int g_brick_generate_cd, g_speed_up_cd, g_food_generate_cd,g_refresh_cd;
 int g_input_interval; 
 int g_refresh_x_limit,g_refresh_y_limit; 
 int g_brick_generate_cd;
 int g_brick_number; 
 int g_input_time_limit;
 int g_continuous_key_down;
 int g_speed;
 int g_step_counter;
 int g_food_counter;
 long g_score;
 int g_HP;
 int g_MP;
 int g_step_counter;
 int it_user_input_loop_times,food_cast_times;
 char g_anouncement[100];
 char g_screen_parttern[x_asix_length][y_asix_length];
 enum Class {dog,food,brick,object,nothing};

 HANDLE g_consoleHandle;
 COORD g_originPointCoord,g_gameDataCoord,g_announcementCoord;



#endif	
