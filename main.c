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
printf("��˾��������������ʱ��������%d���룬�����������",g_input_interval);

	
/* the original code before time_control  is induce
if(g_input_interval>1000f){
g_speed=g_speed*0.8f;
SetConsoleCursorPosition(g_consoleHandle,g_announcementCoord);
printf("��˾�������������ٶ�Ϊ%d �����������",g_speed/100);
//getch();	
}
else if(g_speed < 8000){
g_speed*=1.1f; 
SetConsoleCursorPosition(g_consoleHandle,g_announcementCoord);
printf("��˾�������������ٶ�Ϊ%d �����������",g_speed/100);
//getch();	
}
else if(g_speed < 16000){	
g_speed*=1.05f; 
SetConsoleCursorPosition(g_consoleHandle,g_announcementCoord);
printf("��˾�������������ٶ�Ϊ%d �����������",g_speed/100);
//getch();	
}
*/
}//function end 


void printIntroduction(){
	printf("      \n ̰������Ϸ �������:\n \n \n");  
	printf("���ֲ�����������שͷ�����˻��Ѫ������Խ�󣬵�ѪԽ��\n");
	printf("��ĸHMTS ���ǿ��ԳԵģ�H�Ǽ�Ѫ��Health Point����M�Ǽ�ħ����Magic Point����T�Ǽ��٣�Timmer++����S�����ӷ�����Score��\n");
	printf("ǿ�ҽ���Զ���ǰ�����٣��ٶ�Խ��Ч��Խ�ã���Ȼ��ʧ�����˷���ҲԽ��,No Risk No Gain\n");
	printf("Ƶ�������������ӷ�����ħ��ֵ����ͬʱҲ�������ٶȣ��Ӷ����ӷ���\n"); 
	printf("WASD���Ʒ���QERFZXC�ֱ��Ӧ���ܣ��������������٣�������ˢ�£��ռ���Ծ����ͷ\n");
	
	printf("СTips��������f��������Ի��򣬷������ֻ��ڵ�������ߡ�ˢ����Ҫ�ķ�1��ħ��\n");
	printf("���������ʼ��Ϸ\n");
	getch();
	printf("�ٰ�һ�¿�ʼ��Ϸ\n");
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
  printf("|��˾��Ҫ������������|");
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
  printf("|����������ʮ�Σ�ħ��ֵ��һ�����һ��|");
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


