#include "Data_Proccessor.h"


enum Boolean whether_hitting_brick
(struct Brick * brick_pointer)
{if(brick_pointer->x==g_head_dog_pointer->x &&
    brick_pointer->y==g_head_dog_pointer->y){return true;}
    else{return false;}
}

enum Boolean whether_hitting_dog(struct Dog * dog_pointer)
{if(  dog_pointer!=g_head_dog_pointer       &&
      dog_pointer->x==g_head_dog_pointer->x &&
      dog_pointer->y==g_head_dog_pointer->y   
   )
     {return true;}
	 else{return false;}
}
enum Boolean whether_eating_food(struct Food * food_pointer)
{if(food_pointer->x==g_head_dog_pointer->x &&
      food_pointer->y==g_head_dog_pointer->y)
   {return true;}else{return false;}
}

void clean_announcement(){
	SetConsoleCursorPosition(g_consoleHandle,g_announcementCoord);
	printf("                                                     ");
	SetConsoleCursorPosition(g_consoleHandle,g_announcementCoord);
} 

void play_music(enum SongName songName){
 
 switch(songName){
  	
   case hit_brick:
     Beep(100,20);
     Beep(10,20);
     Beep(600,20);
     Beep(100,20);
   break;
   case eat_HP:
     Beep(290,10);
     Beep(102,10);
     Beep(770,10);
	 Beep(60,10);
	 Beep(10,10);
     Beep(100,10);
        break;
   case eat_Majc:
     Beep(100,10);
     Beep(3400,10);
     Beep(2,10);
     Beep(200,10);
	 Beep(20,10);
     Beep(2000,10);
	 Beep(72,10);
     Beep(260,10);
     break;
     
  case eat_score:
     Beep(66,20);
     Beep(70,20);
     Beep(7,20);
     Beep(90,20);
     break;
  
  case eat_timmer:
        Beep(226,20);
     Beep(30,20);
     Beep(7,20);
     Beep(450,20);
     break;
  case game_over:
     Beep(663,20);
     Beep(730,20);
     Beep(27,20);
     Beep(90,20);
     break;
     
  
  
  
  }//switch end
fflush(stdin);
}//function end

 
 void printInfo(){
 	
  SetConsoleCursorPosition(g_consoleHandle,g_gameDataCoord);
	 
  printf("score %d ",g_score);
  printf("MP %d ",g_MP);
  printf("HP %d ",g_HP);
  printf("输入时间 %d毫秒", g_input_interval);
  printf("step %d ",g_step_counter);
  printf("\n x %d y  %d \n",g_head_dog_pointer->x,g_head_dog_pointer->y);
  printf("wasd方向 \n");
  printf("连续操作方向键可增加分数和MP \n"); 
  printf("魔法施放 ：z加速 x 空间跳跃 c 掉头 e 减速 q大召--神罗天征 r自愈 f清除文字气泡（消耗魔法1点）");
 
  printf("\n");
  
 }



void handle_event()
{
SetConsoleCursorPosition(g_consoleHandle,g_announcementCoord);
struct Object * checking_object_pointer;
struct Brick * brick_pointer;
struct Food * food_pointer;
struct Dog * dog_pointer; 

checking_object_pointer=g_object_link_head_pointer;
 
while(checking_object_pointer!=0){
	
switch(checking_object_pointer->source_object_class)
 {case brick:
  
   brick_pointer=(struct Brick *)
   (checking_object_pointer->source_object_pointer);
 
   if(whether_hitting_brick(brick_pointer))
   { 
   (*g_data_proccessor.play_music)(hit_brick);
   (*g_brick_manager.handle_hitting_event)(brick_pointer);
    return;
	}
   break;
  
  case dog:
  dog_pointer=(struct Dog *)
   (checking_object_pointer->source_object_pointer);
 
  if(whether_hitting_dog(dog_pointer))
  { (*g_data_proccessor.play_music)(game_over);
  g_game_over=true;
  return;
  }
   break;
      
 case food: 
 food_pointer=(struct Food *)
 (checking_object_pointer->source_object_pointer);
     
 if(whether_eating_food(food_pointer))
  {
  g_food_counter--;
  (*g_food_manager.eating_event_handle)(food_pointer);
 // (*g_food_manager.make_a_random_food)();	   
  return;
  }
  break;
}//switch end
 checking_object_pointer=checking_object_pointer->latter;
 }//while end
 (*g_data_proccessor.clean_announcement)();
}
 
 
 
void clean_and_free_ram(void * pointer,int x,int y)
{   COORD eraseCoord; 
	free(pointer);
	pointer=0;
	g_screen_parttern[x][y]=' ';
	
	eraseCoord.X=x;
	eraseCoord.Y=y;
	
	(*g_data_proccessor.draw_point)(eraseCoord);
} 

void calculate_next_xy_by_vector
(int x_start,int y_start,int x_end,int y_end,
int * new_x_pointer,int * new_y_pointer)
{/*calculate new x, */ 
 if(x_start==x_end)
 {*new_x_pointer=x_start;}
  else if(x_start<x_end)
 {*new_x_pointer=(x_start+1);}
      else{*new_x_pointer=(x_start-1);}   
/*calculate new y*/
 if(y_start==y_end){*new_y_pointer=y_start;}
 else if(y_start<y_end){*new_y_pointer=(y_start+1);}
      else{*new_y_pointer=(y_start-1);}   
}/*function end*/


void draw_screen(){
	
int x;
int y;
char parttern;
SetConsoleCursorPosition(g_consoleHandle,g_originPointCoord);
system("cls");
  
 /*printf("drawing screen \n");*/
 for (y=0; y<y_asix_length; y++){
  for(x=0; x<x_asix_length; x++){
  	
//printf("test");
   parttern=g_screen_parttern[x][y];
    
    setPartternColor(parttern);
	 
   printf("%c",parttern); 
   
   }/*inner for*/
   
   printf("\n"); 
   }
 //outter for

printf("%s \n",g_anouncement);
//Sleep(11); 
//printf("\n now print info \n");
printInfo();
 
}

void draw_screen_area(int x_limit,int y_limit)
{int x; int y;
char parttern;
 system("cls");
 
 
 /*printf("drawing screen \n");*/
 for (y=0; y<y_asix_length; y++)
 {
  for(x=0; x<x_asix_length; x++)
  {
   parttern=g_screen_parttern[x][y];
   
    setPartternColor(parttern);
   printf("%c",parttern);
   
  }/*inner for*/
 printf("\n"); 
  }//outter for
//  printf("%s \n",g_anouncement);
 //sleep(111); 
}//function end


void draw_point(COORD coord){
//printf("test draw point 0 \n");
   HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleCursorPosition(handle,coord);
   
    setPartternColor(g_screen_parttern[coord.X][coord.Y]);
   printf("%c",g_screen_parttern[coord.X][coord.Y]);
 
}

void setCursorInDefaultHandle(int x,int y){
  COORD coord;
  coord.X=x;
  coord.Y=y;
  SetConsoleCursorPosition(g_consoleHandle,coord);
}


void setPartternColor(char parttern){
	 if(isdigit(parttern))
     SetConsoleTextAttribute(g_consoleHandle,FOREGROUND_RED);
     else if(isalpha(parttern)>0)
     SetConsoleTextAttribute(g_consoleHandle,0x06);
	 else if(ispunct(parttern)>0)
	 SetConsoleTextAttribute(g_consoleHandle,FOREGROUND_GREEN); 
	 else 
	 SetConsoleTextAttribute(g_consoleHandle,7); 	
	
}

struct Data_Proccessor make_data_proccessor() 
{struct Data_Proccessor data_proccessor;
 data_proccessor.draw_screen=&draw_screen;
 data_proccessor.clean_and_free_ram=&clean_and_free_ram;
 data_proccessor.calculate_next_xy_by_vector=&calculate_next_xy_by_vector;	
 data_proccessor.handle_event=&handle_event;
 data_proccessor.clean_and_free_ram=&clean_and_free_ram;
 data_proccessor.draw_point=&draw_point;
 data_proccessor.clean_announcement=&clean_announcement;
 data_proccessor.printInfo=&printInfo;
 data_proccessor.play_music=&play_music;
 data_proccessor.setCursorInDefaultHandle=&setCursorInDefaultHandle;
 data_proccessor.setPartternColor=&setPartternColor;
 data_proccessor.current_timestamp=&current_timestamp;
 return data_proccessor;
} //function


	 


long long current_timestamp(){

struct timeval te; 
gettimeofday(&te, NULL); // get current time
long long milliseconds = te.tv_sec*1000LL + te.tv_usec/1000; // calculate milliseconds
// printf("milliseconds: %lld\n", milliseconds);
return milliseconds;

	
}