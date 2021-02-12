
#include "stdio.h"
 
#include "Dog_Manager.h"
#include "Brick_Manager.h"
#include "Food_Manager.h"
#include "Object_Data_Recorder.h"
#include "Data_Proccessor.h"




void initialize()
{int made_brick=0;
 g_dog_manager=make_dog_manager();
 g_brick_manager=make_brick_manager();
 g_food_manager=make_food_manager();
 g_object_data_recorder=make_object_data_recorder();
 g_data_proccessor=make_data_proccessor();
 g_user_input_time=300; 
 g_game_over=false;
 g_step_counter=0;
 g_food_counter=0;

 g_HP=100;
 g_MP=100;
 g_step_counter=0; 
 g_move_direction=stay;
   
  
 g_object_link_head_pointer=
   (*g_object_data_recorder.make_object_link)();
 
 
 g_head_dog_pointer=(*g_dog_manager.make_a_dog_queue)(5,4,7,7);
 (*g_brick_manager.make_4_wall)();
  
 /* 
 for(made_brick=0;made_brick<20;made_brick++)
  {g_brick_manager.make_a_random_brick();}
  g_speed=10000/g_user_input_time; 
 */
}




int main(int arg_1,int arg_2)
{enum Boolean food_exist;
  initialize();

while(g_game_over!=true){


g_whether_food_exist=
     (*g_object_data_recorder.whether_class_exist)(food);  

 if(g_whether_food_exist==false)
 {
 (*g_food_manager.make_a_random_food)();}

  
 if(g_food_counter>10){
    (*g_brick_manager.make_a_random_brick)();
	 g_food_counter=0;
	}

 (*g_object_data_recorder.update_screen_parttern_record)();
 

 (*g_data_proccessor.draw_screen)();
 (*g_dog_manager.handle_user_input)();
 (*g_dog_manager.move_dog_queue)();
 (*g_data_proccessor.handle_event)();  
 
  g_step_counter++;
if(g_step_counter>15)
{
g_brick_manager.make_a_random_brick();
g_user_input_time-=199;
if(g_user_input_time<=0){g_user_input_time=233;}
g_speed=10000/g_user_input_time; 
printf("老司机加速啦！现速度为%d 按任意键继续",g_speed);getch();
g_step_counter=0;
} 
 }//while end
printf("\n game over ");
sleep(10000);
}// main function end
