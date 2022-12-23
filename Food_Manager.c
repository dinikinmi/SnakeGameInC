#include "Food_Manager.h"

char get_food_parttern(struct Food * food)
{
if(food==0){return ' ';}
 switch(food->type)
 {case hp:
  return 'H';
  
  case mp:
  return 'M';
  
  case time_slow:
  return 'T';
  
  case score:
  return 'S';
 }

}

void make_a_food(int x,int y,enum Food_Type type)
{struct Food * food_pointer;
 food_pointer=(struct Food*)
              malloc( sizeof(struct Food) );
 food_pointer->x=x;
 food_pointer->y=y;
 food_pointer->type=type;
 (*g_object_data_recorder.add_new_object)
 ((void*)food_pointer,food,x,y);
 g_food_counter++;
}



void make_a_random_food()
{int x,y,food_code;
 enum Class object_class;
 enum Food_Type food_type;  

 do  
 {x=rand()%x_asix_length;
  y=rand()%y_asix_length;
  if(x<1){continue;}
  if(y<1){continue;}
  object_class=(*g_object_data_recorder.get_class_by_xy)(x,y);
 }while(object_class!=nothing);
 	
 food_code=rand()%9;
 switch(food_code)
 {
 case 0 :
  food_type=score;break;
 case 1:
  food_type=hp;break;
 
 case 2:
 case 3:
 food_type=mp;
 break;
 
 case 4:
 food_type=time_slow;break;
 default :
  food_type=score;break;
 
 }//switch end
make_a_food(x,y,food_type);

}




void eating_event_handle(struct Food * eaten_food_pointer)
{ float speed_coefficent=0.3;
   int increment;
  g_food_counter--;
	switch(eaten_food_pointer->type)
	{
	case hp:
	increment=g_speed*speed_coefficent;
	if(increment<1){increment=1;} 
	g_HP=g_HP+increment;
	
	SetConsoleCursorPosition(g_consoleHandle,g_announcementCoord);
	printf
	("以%d速度吃了加血药丸，增加%d血量，速度越快增加越多，按任意键继续",
	g_speed,increment);
    getch();
    SetConsoleCursorPosition(g_consoleHandle,g_announcementCoord);
	printf
	("                                                                   ");
    SetConsoleCursorPosition(g_consoleHandle,g_announcementCoord);
	
    
	break;
	
	case mp:
	increment=g_speed * speed_coefficent; 
    if(increment<1){increment=1;} 
	g_MP+=increment;
    printf
	("以%d速度吃了魔法药丸，增加%d魔法，速度越快效果越好，按任意键继续",
	g_speed,increment);
    getch();	  
	break;
	
	case time_slow:
     g_speed*=0.6;
	printf("吃了减速药丸，速度下降6成，任意键继续"); 
	getch();
	break;
	
	case score:
	increment=999*g_speed*speed_coefficent;
	g_score+=increment;
    printf
	("以%d速度吃了加分药丸，增加%d分数，速度越快效果越好，按任意键继续",
	g_speed,increment);
	getch();
	(*g_dog_manager.add_new_dog_to_queue_tail)();
   	break;
	}
 (*g_object_data_recorder.delete_an_object)
 ((void*)eaten_food_pointer);
 
}



struct Food_Manager make_food_manager()
{struct Food_Manager food_manager;
 food_manager.make_a_random_food=&make_a_random_food;
 food_manager.make_a_food       =&make_a_food;
 food_manager.eating_event_handle
                                =&eating_event_handle; 
 food_manager.get_food_parttern= &get_food_parttern;
 return food_manager;
}

