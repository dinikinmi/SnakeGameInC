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
     {return true;}else{return false;}
}
enum Boolean whether_eating_food(struct Food * food_pointer)
{if(food_pointer->x==g_head_dog_pointer->x &&
      food_pointer->y==g_head_dog_pointer->y)
   {return true;}else{return false;}
}
 

void handle_event()
{
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
   {(*g_brick_manager.handle_hitting_event)(brick_pointer);
    return;}
   break;
  
  case dog:
  dog_pointer=(struct Dog *)
   (checking_object_pointer->source_object_pointer);
 
  if(whether_hitting_dog(dog_pointer))
  {g_game_over=true;
  return;}
   break;
      
 case food: 
 food_pointer=(struct Food *)(checking_object_pointer->source_object_pointer);
 if(whether_eating_food(food_pointer))
  {(*g_food_manager.eating_event_handle)(food_pointer);
  
   (*g_food_manager.make_a_random_food)();	   
   return;
  }
  break;
}//switch end
 checking_object_pointer=checking_object_pointer->latter;
 }//while end
}
 
 
 
void clean_and_free_ram(void * pointer)
{
	free(pointer);
	pointer=0;
} 

void calculate_next_xy_by_vector
(int x_start,int y_start,int x_end,int y_end,
int * new_x_pointer,int * new_y_pointer)
{//calculate new x, 
 if(x_start==x_end)
 {*new_x_pointer=x_start;}
  else if(x_start<x_end)
 {*new_x_pointer=(x_start+1);}
      else{*new_x_pointer=(x_start-1);}   
//calculate new y
 if(y_start==y_end){*new_y_pointer=y_start;}
 else if(y_start<y_end){*new_y_pointer=(y_start+1);}
      else{*new_y_pointer=(y_start-1);}   
}//function end

void draw_screen()
{int x; int y;
char parttern;
 system("cls");
 
  printf("score %d ",g_score);
  printf("MP %d ",g_MP);
  printf("HP %d ",g_HP);
  printf("speed %d ", g_speed);
  printf("step %d ",g_step_counter);
  printf("\n x %d y  %d \n",g_head_dog_pointer->x,g_head_dog_pointer->y);
  printf("wasd方向 z时空转移 ");
printf("x调头 c大招 e减速 q自愈 r加速 ");
printf("\n");
  
 
 //printf("drawing screen \n");
 for (y=0; y<y_asix_length; y++)
 {
  for(x=0; x<x_asix_length; x++)
  {
   parttern=g_screen_parttern[x][y];
   printf("%c",parttern);
   
  }//inner for
 printf("\n"); 
  }//outter for
//  printf("%s \n",g_anouncement);
 //sleep(111); 
}//function end


struct Data_Proccessor make_data_proccessor() 
{struct Data_Proccessor data_proccessor;
 data_proccessor.draw_screen=&draw_screen;
 data_proccessor.clean_and_free_ram=&clean_and_free_ram;
 data_proccessor.calculate_next_xy_by_vector=&calculate_next_xy_by_vector;	
 data_proccessor.handle_event=&handle_event;
 data_proccessor.clean_and_free_ram=&clean_and_free_ram;
 return data_proccessor;
} //function


	 





