#include "Dog_Manager.h"    



void drawDogQueue(){
  struct Dog * tempPointer=g_head_dog_pointer;
  struct Dog * next_dog;
  HANDLE handle ; 
  int x,y;
  COORD coord={0,0};
   //printf("test draw dog queue 0 \n");
handle=GetStdHandle(STD_OUTPUT_HANDLE);
(*g_object_data_recorder.update_screen_parttern_record)();
   do{
   	 
	 x=tempPointer->x;
     y=tempPointer->y;
     coord.X=x;
     coord.Y=y;
     
     SetConsoleCursorPosition(handle,coord);
	 printf("%c",g_screen_parttern[x][y]); 
	 
      //  printf("test draw dog queue 1 \n");
     
	 next_dog=
	  get_next_dog_by_lengthen_direction(tempPointer);
     
  	 if(next_dog==0)
  	   drawTail(tempPointer);
 	  else tempPointer=next_dog;
  	  
  	  //  printf("test draw dog queue 2 \n");
     
  	  
	  }while(next_dog!=0);
	  
	  coord.X=0;
	  coord.Y=0;
	  SetConsoleCursorPosition(handle,coord);
  	
}
//function end

void drawTail(struct Dog * tail_dog){
  COORD coord_up,coord_down,coord_left,coord_right,coord_mid;
  //printf("test draw tail \n");
   coord_up.X=tail_dog->x;
   coord_up.Y=tail_dog->y+1;
   
   coord_down.X=tail_dog->x;
   coord_down.Y=tail_dog->y-1;
   
   coord_left.X=tail_dog->x-1;
   coord_left.Y=tail_dog->y;
   
   coord_right.X=tail_dog->x+1;
   coord_right.Y=tail_dog->y;
   
   (*g_data_proccessor.draw_point)(coord_up);
   (*g_data_proccessor.draw_point)(coord_down);
        
   (*g_data_proccessor.draw_point)(coord_right);
   (*g_data_proccessor.draw_point)(coord_left);
   
  
}

char get_dog_parttern(struct Dog * dog){
 //if(dog==0)return ' ';
  switch(dog->role)
   {case head_dog:
      return '@';
    case tail_dog:
      return '~';
	case middle_dog:
	  return '*';
	}
}



struct Dog * make_a_new_dog(int x,int y)
{	 struct Dog * new_dog_pointer;
  	
	new_dog_pointer=(struct Dog*)malloc(sizeof(struct Dog)); 
    new_dog_pointer->x=x;  
    new_dog_pointer->y=y;
	new_dog_pointer->formor=0;
	new_dog_pointer->latter=0;
	
	(*g_object_data_recorder.add_new_object)
	                  ((void *)new_dog_pointer,dog,x,y);
	
    return new_dog_pointer;
}
//β��������Ҫȷ��������©���� ������
//Ŷ��������ȷ��Ҳ�С�����Ϊ���ƶ���ʱ��������ǰ�湷����λ�� 
struct Dog * add_new_dog_to_queue_tail()
{ struct Dog * new_tail_dog_pointer;
  struct Dog * temp_pointer;
  enum Lengthen_Direction lengthen_direction;
  
  struct Dog * old_tail_dog_pointer;
  
  new_tail_dog_pointer=make_a_new_dog(0,0);
  old_tail_dog_pointer=g_dog_manager.get_tail_dog_pointer();
   
  
  if(old_tail_dog_pointer==0)//if the snake have only one dog,it is the head dog;
  {temp_pointer=g_head_dog_pointer;}
  else
  {temp_pointer=old_tail_dog_pointer;}
  
  lengthen_direction=(*g_dog_manager.get_lengthen_direction)();
  
  switch(lengthen_direction)
  {
  case latter:
   temp_pointer->latter=new_tail_dog_pointer;
   new_tail_dog_pointer->formor=temp_pointer;break;
   
  case formor:
   temp_pointer->formor=new_tail_dog_pointer;
   new_tail_dog_pointer->latter=temp_pointer;break;
  }
  
  if(temp_pointer->role==tail_dog)
  //if it is not tail,it will be head
  {temp_pointer->role=middle_dog;}
  
  new_tail_dog_pointer->role=tail_dog;
  return new_tail_dog_pointer;	 
 }
 
struct Dog * make_a_dog_queue
(int start_x,int start_y,
 int end_x,  int end_y)
{int new_dog_x,new_dog_y;

 struct Dog * formor_dog_pointer;
 struct Dog * new_dog_pointer; 
 struct Dog * head_dog_pointer;
 
 head_dog_pointer=(*g_dog_manager.make_a_new_dog)
                  (start_x,start_y);
 head_dog_pointer->role=head_dog;                 
 formor_dog_pointer=head_dog_pointer;
 	while(true){
 (*g_data_proccessor.calculate_next_xy_by_vector)
 (formor_dog_pointer->x,
  formor_dog_pointer->y,
  end_x,end_y,  
  &new_dog_x,
  &new_dog_y
  ); 
  new_dog_pointer=(*g_dog_manager.make_a_new_dog)
                  (new_dog_x,new_dog_y);
 new_dog_pointer->formor=formor_dog_pointer;
 formor_dog_pointer->latter=new_dog_pointer;
 
 if(new_dog_x==end_x & new_dog_y==end_y)
   {break;}else{
    new_dog_pointer->role=middle_dog;
	formor_dog_pointer=new_dog_pointer;
	}  

 }//while loop end
  new_dog_pointer->role=tail_dog;
  return head_dog_pointer;
}



void move_dog_queue()
{int temp_x1,temp_y1,temp_x2,temp_y2;
 //enum Boolean move_snake_body_finish=false;
 enum Lengthen_Direction lengthen_direction;
 struct Dog * operating_dog_pointer;
 operating_dog_pointer=g_head_dog_pointer;
  
 temp_x1=operating_dog_pointer->x;
 temp_y1=operating_dog_pointer->y;
 //move the head,convey the head posi to 2cd, 2cd to 3rd...
 switch(g_move_direction)
 {case up:
   operating_dog_pointer->y-=1;break;
  case down:
   operating_dog_pointer->y+=1;break;
  case left:
   operating_dog_pointer->x-=1;break;
  case right:
   operating_dog_pointer->x+=1;break;
  case stay:
    return;
 }//switch end
   if(operating_dog_pointer->x > x_asix_length-1)
    {operating_dog_pointer->x=0;}
   if(operating_dog_pointer->x < 0)
    {operating_dog_pointer->x=x_asix_length-1;}
    
   if(operating_dog_pointer->y > y_asix_length-1)
    {operating_dog_pointer->y=0;}
   if(operating_dog_pointer->y < 0)
    {operating_dog_pointer->y=y_asix_length-1;}
   
    
  lengthen_direction=get_lengthen_direction();
  
  operating_dog_pointer=get_next_dog_pointer
    (operating_dog_pointer,lengthen_direction);
// convey the coordination of this dog to the next dog
   while(operating_dog_pointer!=0)
   {
    temp_x2=operating_dog_pointer->x;  
    temp_y2=operating_dog_pointer->y;
	operating_dog_pointer->x=temp_x1; 
	operating_dog_pointer->y=temp_y1;
    
	temp_x1=temp_x2; 
	temp_y1=temp_y2;
	
	operating_dog_pointer=get_next_dog_pointer
    (operating_dog_pointer,lengthen_direction);
  }//while loop end
 
 drawDogQueue();
 
}//move_dog_queue function end


struct Dog * get_next_dog_by_lengthen_direction
(struct Dog * now_operating_dog_pointer)
{
 enum Lengthen_Direction lengthen_direction;
    lengthen_direction =get_lengthen_direction();
 //printf("test get next dog by direction \n");
 
 if(now_operating_dog_pointer==0){
 
 return 0;}
  switch(lengthen_direction)
 {case formor:
   return now_operating_dog_pointer->formor;
 
  case latter:
   return now_operating_dog_pointer->latter;
 }
} 


struct Dog * get_next_dog_pointer
(struct Dog * now_operating_dog_pointer,
 enum Lengthen_Direction lengthen_direction)
{
 if(now_operating_dog_pointer==0){
 
 return 0;}
  switch(lengthen_direction)
 {case formor:
   return now_operating_dog_pointer->formor;
 
  case latter:
   return now_operating_dog_pointer->latter;
 }
} 

struct Dog * get_tail_dog_pointer()
{struct Dog *  now_checking_dog_pointer;
 struct Dog *  next_dog_pointer;
 enum Lengthen_Direction lengthen_direction;
 
  if(g_head_dog_pointer->latter==0 && 
     g_head_dog_pointer->formor==0)
	 {return 0;}//ֻ��һ��ͷ����û��β�����  
 now_checking_dog_pointer=g_head_dog_pointer;
 lengthen_direction=get_lengthen_direction();
 while(1){
  next_dog_pointer=get_next_dog_pointer
    (now_checking_dog_pointer,lengthen_direction);   
  
 if(next_dog_pointer==0){return now_checking_dog_pointer;}
  else{now_checking_dog_pointer=next_dog_pointer;}
  }//while end

}//function end


void queue_u_turn()
{struct Dog * original_tail_dog_pointer;
 original_tail_dog_pointer=get_tail_dog_pointer();
  if(original_tail_dog_pointer!=0)//����ֻ��һͷ��û��β�� 
  {g_head_dog_pointer->role=tail_dog;
   original_tail_dog_pointer->role=head_dog;
   g_head_dog_pointer=original_tail_dog_pointer;
   g_move_direction=stay;
  }
}


void handle_user_input()
{int temp_loop_times;
 int user_input;
 int wait=0;
 int wait_limit=100000/g_speed;
 temp_loop_times=g_input_time_limit;
 fflush(stdin);
 
 while(wait<wait_limit){
 
  fflush(stdin);
   if(_kbhit())//if user inputed something
    {user_input=getch();
    g_continuous_key_down++;
    
    fflush(stdin);
     switch(user_input)
	 {
	  case key_w:
      if(g_move_direction!=down)
	  {g_move_direction=up;  fflush(stdin);}return;	
	  //inputing an anti direction will lead to self eating
      case key_s:
	  if(g_move_direction!=up)
	  {g_move_direction=down;  fflush(stdin);}return;
	  
	  case key_a:
	  if(g_move_direction!=right)
	  {g_move_direction=left;  fflush(stdin);}return;
	  
	  case key_d:
	  if(g_move_direction!=left)
	  {g_move_direction=right;  fflush(stdin);}return;
	  
	  case key_z:
	  majic_teleport();break;
	  
	  case key_x:
	  majic_u_turn();break;
	 
	  case key_c:
	  majic_clean_all_brick();
	  g_brick_manager.make_4_wall();
	  break;
	 
      case key_e:
      majic_slow_down();break;
      
      case key_q:
      majic_heal();break;
      
      case key_r:
	  majic_accelerate(); break;
	  

	  default :
	    return;  
	}//switch end
   	
  }else
	{Sleep(1);
	 wait++;
	 }
  
  }//while end
 
} 

enum Lengthen_Direction get_lengthen_direction()
{if(g_head_dog_pointer->latter==0&&
    g_head_dog_pointer->formor==0)
 {return latter;}
 else if(g_head_dog_pointer->latter!=0)
 {return latter;}
 else{return formor;}

}

void majic_teleport()
{int aims_x,aims_y;
 enum Boolean user_confirm;
 user_confirm=false;
 if(g_MP<5)
 {  
  strcpy(g_anouncement,"ʱ��ת��ʧ�ܣ�ħ������");}
  else{
  g_MP=g_MP-5;
 do{ 
 printf("��ʼ�ռ�ת�� ");
 printf("������Ҫ�����x����");
 fflush(stdin);
 scanf("%d",&aims_x,1);
 printf("������Ҫ�����y���� ");
 fflush(stdin);
 scanf("%d",&aims_y,1); 
 printf(" %d %d ",aims_x,aims_y);
 fflush(stdin);
  g_move_direction=stay;
  if(aims_x>x_asix_length-1){aims_x=x_asix_length-1;}
  if(aims_x<0){aims_x=1;}
  
  if(aims_y>y_asix_length-1){aims_y=y_asix_length-1;}
  if(aims_y<0){aims_y=1;}
 
   printf("q %d %d ",aims_x,aims_y);getch();
   
  g_head_dog_pointer->x=aims_x;
  g_head_dog_pointer->y=aims_y;
  g_object_data_recorder.update_screen_parttern_record();
  g_data_proccessor.draw_screen();
   
   printf("�������"); 
 //  printf("qq %d %d ",aims_x,aims_y);
   
  
  user_confirm=wait_user_confirm("ȷ��ת�Ƶ���������"); 
  if(user_confirm==true){printf("ʱ��ת�Ƴɹ��������ⷽ�������");} 
  }while(user_confirm!=true);
   //if end 
 }//else end	
}// function end 

void majic_u_turn()
{if(g_MP>=1)
  {g_MP-=1;
   queue_u_turn();
   g_move_direction=stay; 
  printf("��ͷ�ɹ����ķ�1��ħ��, �������뷽�������Ϸ");getch();    
  }
}

void majic_clean_all_brick()
{enum Boolean user_confirm;
 SetConsoleCursorPosition(g_consoleHandle,g_announcementCoord);
 if(g_MP>=50)
 { user_confirm=wait_user_confirm("�ռ����л�ķ�ȫ��ħ����Ѫ����ȷ��Ҫ�ͷ���");
  if(user_confirm==true)
   {g_MP=0; g_HP=1;
    g_object_data_recorder.delete_a_class(brick);
    (*g_object_data_recorder.update_screen_parttern_record)();
    (*g_data_proccessor.draw_screen)();
    printf("�����ͷ���ɣ�HP MP�ľ�,���������������Ϸ\n");
	getch(); 
   }//user confirm if end
   	else{ strcpy(g_anouncement,"ħ�����㣬�Ų����ռ�����"); 
   
   }//user confirm else end
 }else{
 strcpy(g_anouncement,"ħ������50���Ų����ռ�����");
  }//g_MP if  end
  
	
}


void majic_slow_down()
{ SetConsoleCursorPosition(g_consoleHandle,g_announcementCoord);

 if(g_MP>=10)
  {g_MP-=10;
   g_speed*=0.5f;
   printf("���ٳɹ�,�ٶȼ��� �����������");
   getch();
  }else{
   printf("ħ������,�޷����� ���������");
   getch();
  }
   (*g_data_proccessor.clean_announcement)();  
	
}
 
 void majic_accelerate()
 {
  SetConsoleCursorPosition(g_consoleHandle,g_announcementCoord);
  g_speed*=1.2f;
	printf("ʩ���ɹ�������20%��ף���ˣ������������ ");
	getch(); 
	(*g_data_proccessor.clean_announcement)();
  }
 
 void majic_heal()
 {
 SetConsoleCursorPosition(g_consoleHandle,g_announcementCoord);
 if(g_MP>=4)
   {g_MP-=4;
    g_HP+=3;
	printf("�ɹ��ָ�3��HP������4��ħ��,�����������" );
	getch(); 
	(*g_data_proccessor.clean_announcement)();
  }else{
  printf("�ɹ��ָ�3��HP,�����������" );
  getch(); 
  (*g_data_proccessor.clean_announcement)();
 }//else end 
  (*g_data_proccessor.clean_announcement)();
 
 }
 
 
 enum Boolean wait_user_confirm(char * message)
 {char user_input;
 SetConsoleCursorPosition(g_consoleHandle,g_announcementCoord);
 
 printf("ȷ�ϣ�"); 
  printf("%s",message);

 while(true){
  printf("ȷ��������Y�س�������������N�س�");
  fflush(stdin); 
  scanf("%c",&user_input,1);
  fflush(stdin);
  if(user_input=='y'||user_input=='Y')
   {
    (*g_data_proccessor.clean_announcement)();
     
	return true;
   
   }else if(user_input=='n'||user_input=='N')
   {
   	SetConsoleCursorPosition(g_consoleHandle,g_announcementCoord);
  printf("                                                           ");
  
  
   return false;}
    else{
(*g_data_proccessor.clean_announcement)();
SetConsoleCursorPosition(g_consoleHandle,g_announcementCoord);
	 printf("������������������");
 
 
 }
 }//while end
 }//function end


struct Dog_Manager make_dog_manager()
{
struct Dog_Manager dog_manager;
dog_manager.get_tail_dog_pointer =&get_tail_dog_pointer; 
dog_manager.make_a_dog_queue     =&make_a_dog_queue; 
dog_manager.add_new_dog_to_queue_tail
                                 =&add_new_dog_to_queue_tail;       
dog_manager.make_a_new_dog       =&make_a_new_dog;
dog_manager.queue_u_turn         =&queue_u_turn;                 
dog_manager.get_lengthen_direction=&get_lengthen_direction; 
dog_manager.move_dog_queue       =&move_dog_queue; 
dog_manager.get_next_dog_pointer =&get_next_dog_pointer;
dog_manager.get_dog_parttern     =&get_dog_parttern; 
dog_manager.handle_user_input    =&handle_user_input;
dog_manager.majic_teleport       =&majic_teleport;
dog_manager.majic_u_turn         =&majic_u_turn;
dog_manager.majic_slow_down      =&majic_slow_down;
dog_manager.majic_clean_all_brick=&majic_clean_all_brick;
dog_manager.majic_heal           =&majic_heal;
dog_manager.wait_user_confirm    =&wait_user_confirm;
dog_manager.majic_accelerate     =&majic_accelerate;
return dog_manager;
}

 
