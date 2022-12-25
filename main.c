#include "stdio.h" 
#include "Dog_Manager.h"
#include "Brick_Manager.h"
#include "Food_Manager.h"
#include "Object_Data_Recorder.h"
#include "Data_Proccessor.h"

void setConsoleSize(){

// Set up the handles for reading/writing:
//wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
//rHnd = GetStdHandle(STD_INPUT_HANDLE);
// Change the window title:
SetConsoleTitle("Advanced C tutorial - programming-technique.blogspot.com");
// Set up the required window size:

SMALL_RECT windowSize = {0, 0,x_asix_length+10,y_asix_length+10};
SetConsoleWindowInfo(g_consoleHandle, 1, &windowSize);
// Change the console window size:
// Create a COORD to hold the buffer size:

//COORD bufferSize = {10, 10};
//SetConsoleScreenBufferSize(g_consoleHandle, bufferSize);
}

void speedUp(){
 if(g_input_interval<100)	
	return;
	else 
	g_input_interval*=0.8f;
SetConsoleCursorPosition(g_consoleHandle,g_announcementCoord);
printf("老司机加速啦！输入时间缩减到%d毫秒，按任意键继续",g_input_interval);

	
/* the original code before time_control  is induce
if(g_input_interval>1000f){
g_speed=g_speed*0.8f;
SetConsoleCursorPosition(g_consoleHandle,g_announcementCoord);
printf("老司机加速啦！现速度为%d 按任意键继续",g_speed/100);
//getch();	
}
else if(g_speed < 8000){
g_speed*=1.1f; 
SetConsoleCursorPosition(g_consoleHandle,g_announcementCoord);
printf("老司机加速啦！现速度为%d 按任意键继续",g_speed/100);
//getch();	
}
else if(g_speed < 16000){	
g_speed*=1.05f; 
SetConsoleCursorPosition(g_consoleHandle,g_announcementCoord);
printf("老司机加速啦！现速度为%d 按任意键继续",g_speed/100);
//getch();	
}
*/
}//function end 


void printIntroduction(){
	printf("      \n 贪吃蛇游戏 规则介绍:\n \n \n");  
	printf("数字不能碰，那是砖头。碰了会掉血，数字越大，掉血越多\n");
	printf("字母HMTS 都是可以吃的，H是加血（Health Point），M是加魔法（Magic Point），T是减速（Timmer++），S是增加分数（Score）\n");
	printf("强烈建议吃东西前先提速，速度越大，效果越好，当然，失控受伤风险也越大,No Risk No Gain\n");
	printf("频繁操作可以增加分数和魔法值，但同时也会增加速度，从而增加风险\n"); 
	printf("WASD控制方向，QERFZXC分别对应技能：神罗天征，减速，自愈，刷新，空间跳跃，掉头\n");
	
	printf("小Tips：定期用f技能清除对话框，否则文字会遮挡你的视线。刷新需要耗费1点魔法\n");
	printf("按任意键开始游戏\n");
	getch();
	printf("再按一下开始游戏\n");
	getch(); 
	
}

void initialize()
{
 g_brick_generate_cd=20;
 g_food_generate_cd=100;
 g_refresh_cd=100;
 g_speed_up_cd=20;
 g_input_interval=1000;
 
 
 g_brick_number=0;
 g_input_time_limit=1000;
 g_continuous_key_down=0;
 g_data_proccessor=make_data_proccessor();
 g_dog_manager=make_dog_manager();
 g_brick_manager=make_brick_manager();
 g_food_manager=make_food_manager();
 g_object_data_recorder=make_object_data_recorder();
 g_consoleHandle=GetStdHandle(STD_OUTPUT_HANDLE);
 g_originPointCoord.X=0;
 g_originPointCoord.Y=0;
 
 g_gameDataCoord.X=0;
 g_gameDataCoord.Y=y_asix_length+2;
 
 g_announcementCoord.X=0;
 g_announcementCoord.Y=g_gameDataCoord.Y+5;
 
 
 

 //g_user_input_time=300; 
 g_game_over=false;
 g_step_counter=-1;
 g_food_counter=0;

 g_HP=100;
 g_MP=100;
 g_step_counter=0; 
 g_speed=2000;
 g_move_direction=stay;
   
  
 g_object_link_head_pointer=
   (*g_object_data_recorder.make_object_link)();
 
 
//printf("test initialize 0 \n");

 g_head_dog_pointer=(*g_dog_manager.make_a_dog_queue)(10,3,10,10);
 
// printf("test initialize 1 \n");

 (*g_brick_manager.make_4_wall)();
//  printf("test initialize 2 \n");

setConsoleSize(); 
 (*g_object_data_recorder.update_screen_parttern_record)();
 (*g_data_proccessor.draw_screen)();

 /* 
 for(made_brick=0;made_brick<20;made_brick++)
  {g_brick_manager.make_a_random_brick();}
  g_speed=10000/g_user_input_time; 
 */


}




int main(int arg_1,int arg_2)
{
enum Boolean food_exist;
//printf(stdout);
 printIntroduction(); 
initialize();



getch();

while(g_game_over!=true){
	
fflush(stdin);
g_whether_food_exist=
(*g_object_data_recorder.whether_class_exist)(food);  


if(g_food_counter<20 && g_food_generate_cd==0){

 (*g_food_manager.make_a_random_food)();
 	g_food_generate_cd=20;
}

  /*
 if(g_food_counter	>10){
 (*g_brick_manager.make_a_random_brick)();
  g_food_counter=0;
}*/

 //printf("test -- main \n");

// (*g_data_proccessor.draw_screen)();
 if(g_step_counter>-1)
 (*g_dog_manager.handle_user_input)();
 
 (*g_dog_manager.move_dog_queue)();
 (*g_data_proccessor.handle_event)();  
 (*g_object_data_recorder.update_screen_parttern_record)();
 (*g_data_proccessor.printInfo)();
  
  g_step_counter++;


if( g_refresh_cd == 0 ){
 (*g_object_data_recorder.update_screen_parttern_record)();
 (*g_data_proccessor.draw_screen)();
 g_step_counter=0;
 g_refresh_cd=100;
}

if(g_brick_generate_cd == 0 ){
g_brick_manager.make_a_random_brick();
 g_brick_generate_cd = 20;	
}
 

if(g_speed_up_cd ==0 ){
	
 speedUp();
 (*g_data_proccessor.setCursorInDefaultHandle)
 (g_head_dog_pointer->x-4,g_head_dog_pointer->y-3);
  printf("-----------------------");
 (*g_data_proccessor.setCursorInDefaultHandle)
 (g_head_dog_pointer->x-4,g_head_dog_pointer->y-2);
  printf("|老司机要加速啦啦啦啦|");
 (*g_data_proccessor.setCursorInDefaultHandle)
 (g_head_dog_pointer->x-4,g_head_dog_pointer->y-1);
   printf("--------------------");
  
  g_speed_up_cd=50;
} 	


 
if(g_continuous_key_down>30){
   g_score+=5;	
   g_MP++;
  g_continuous_key_down=0;


 (*g_data_proccessor.setCursorInDefaultHandle)
    (g_head_dog_pointer->x+2,g_head_dog_pointer->y+1);
 printf("------------------");
(*g_data_proccessor.setCursorInDefaultHandle)
    (g_head_dog_pointer->x+2,g_head_dog_pointer->y+2);
  printf("|连续输入三十次，魔法值加一，获得一分|");
 (*g_data_proccessor.setCursorInDefaultHandle)
    (g_head_dog_pointer->x+2,g_head_dog_pointer->y+3);
  printf("-------------------");
 
  //speedUp();
}

(*g_data_proccessor.clean_announcement)();
g_step_counter++;

g_speed_up_cd--;
g_brick_generate_cd--;
g_food_generate_cd--;
g_speed_up_cd--;
g_refresh_cd--;
//test
//stdout++;
  
}//while end



SetConsoleCursorPosition(g_consoleHandle,g_announcementCoord); 
(*g_data_proccessor.draw_screen)();
printf("\n game over ");
Sleep(10000);
}// main function end


