#include "Food_Manager.h"

unsigned char get_food_parttern(struct Food * food)
{ //char c;
if(food==0){return ' ';}

 switch(food->type)
 {case hp:
  return 'H';
 // return 128;
  
  case mp:
return 'M';
  // return 129;
 
  case time_slow:
   return 'T';
  // return 130;
 
  case score:
    return 'S';
 // return 131;
 
 }

}

void make_a_food(int x,int y,enum Food_Type type)
{struct Food * food_pointer;
 food_pointer=(struct Food*)malloc( sizeof(struct Food) );
 food_pointer->x=x;
 food_pointer->y=y;
 food_pointer->type=type;
 (*g_object_data_recorder.add_new_object)((void*)food_pointer,food,x,y);
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
{ float speed_coefficent=0.03;
   int increment;
  g_food_counter--;
  
	switch(eaten_food_pointer->type)
	{
	case hp:
	(*g_data_proccessor.play_music)(eat_HP);
	increment=g_speed*speed_coefficent;
	if(increment<1){increment=1;} 
	if(increment>30){increment=30;}
	g_HP=g_HP+increment;
	
	//SetConsoleCursorPosition(g_consoleHandle,g_announcementCoord);
	(*g_data_proccessor.setCursorInDefaultHandle)
	  (g_head_dog_pointer->x+1,g_head_dog_pointer->y-1);
     printf("-------------------");
	(*g_data_proccessor.setCursorInDefaultHandle)
	  (g_head_dog_pointer->x+1,g_head_dog_pointer->y-2);
	 printf("|oh Yeah��Ѫ������%d|",increment);    
 	 (*g_data_proccessor.setCursorInDefaultHandle)
	  (g_head_dog_pointer->x+1,g_head_dog_pointer->y-3);
     printf("--------------------"); 

   
    /*
    //printf the message on the below position
	printf
	("��%d�ٶȳ��˼�Ѫҩ�裬����%dѪ�����ٶ�Խ������Խ�࣬�����������",
	g_speed,increment);
	getch();
    SetConsoleCursorPosition(g_consoleHandle,g_announcementCoord);
	printf
	("                                                                   ");
    SetConsoleCursorPosition(g_consoleHandle,g_announcementCoord);
	*/
    
	break;
	
	case mp:
	(*g_data_proccessor.play_music)(eat_Majc);
	increment=g_speed * 0.0003; 
    if(increment<1){increment=1;} 
	g_MP+=increment;

	(*g_data_proccessor.setCursorInDefaultHandle)
	  (g_head_dog_pointer->x+1,g_head_dog_pointer->y-3);

 printf("----------------------------");
	(*g_data_proccessor.setCursorInDefaultHandle)
	  (g_head_dog_pointer->x+1,g_head_dog_pointer->y-2);
	  
  printf("|ħ��ֵ����%d��veryˬ|",increment);   	  
	  
	(*g_data_proccessor.setCursorInDefaultHandle)
	  (g_head_dog_pointer->x+1,g_head_dog_pointer->y-4);
   printf("----------------------------");



/*
    printf
	("��%d�ٶȳ���ħ��ҩ�裬����%dħ�����ٶ�Խ��Ч��Խ�ã������������",
	g_speed,increment);
    getch();	  
*/

	break;
	
	case time_slow:
	(*g_data_proccessor.play_music)(eat_timmer);
        
      if(g_input_interval*1.5<3000)
        g_input_interval*=1.5f;
        else g_input_interval=3000;

	(*g_data_proccessor.setCursorInDefaultHandle)
	  (g_head_dog_pointer->x-1,g_head_dog_pointer->y+2);
     printf("|��ü��ټ�����ǰ����ʱ��Ϊ%d����|",g_input_interval);   
        
   /*
     g_speed*=0.5;

   (*g_data_proccessor.setCursorInDefaultHandle)
	  (g_head_dog_pointer->x-1,g_head_dog_pointer->y+1);
   printf("---------------------");   
	(*g_data_proccessor.setCursorInDefaultHandle)
	  (g_head_dog_pointer->x-1,g_head_dog_pointer->y+2);
     printf("|�ٶȼ��룬�������|");   
	(*g_data_proccessor.setCursorInDefaultHandle)
	  (g_head_dog_pointer->x-1,g_head_dog_pointer->y+3);
   printf("---------------------");   

/*
	printf("���˼���ҩ�裬�ٶ��½�6�ɣ����������"); 
	getch();
*/
	break;
	
	case score:
		(*g_data_proccessor.play_music)(eat_score);

	increment=2*g_speed; 
	g_score+=increment;
	
	
	
 (*g_data_proccessor.setCursorInDefaultHandle)
   (g_head_dog_pointer->x+1,g_head_dog_pointer->y-3);
	printf("----------------------------");
    (*g_data_proccessor.setCursorInDefaultHandle)
	     (g_head_dog_pointer->x+1,g_head_dog_pointer->y-2);	     
    printf("|��������%d^_^|",increment);    
   (*g_data_proccessor.setCursorInDefaultHandle)
     (g_head_dog_pointer->x+1,g_head_dog_pointer->y-1);

/* 
    printf
	("��%d�ٶȳ��˼ӷ�ҩ�裬����%d�������ٶ�Խ��Ч��Խ�ã������������",
	g_speed,increment);
	getch();
*/

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

