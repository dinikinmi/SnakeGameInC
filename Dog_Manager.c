#include "Dog_Manager.h"    





char get_dog_parttern(struct Dog * dog){
 //if(dog==0)return ' ';
  switch(dog->role)
   {case head_dog:
      return '@';
    case tail_dog:
      return '~';
	case middle_dog:
	  return (char)3;
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
	                  ((void *)new_dog_pointer,dog);
	
    return new_dog_pointer;
}
//尾狗的坐标要确定啊。。漏洞啊 、、、
// 哦不。。不确定也行。。因为蛇移动的时候他会获得前面狗狗的位置 
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

}//move_dog_queue function end



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
	 {return 0;}//只有一个头。。没有尾的情况  
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
  if(original_tail_dog_pointer!=0)//可能只有一头，没有尾狗 
  {g_head_dog_pointer->role=tail_dog;
   original_tail_dog_pointer->role=head_dog;
   g_head_dog_pointer=original_tail_dog_pointer;
   g_move_direction=stay;
  }
}


void handle_user_input()
{int temp_loop_times;
 int user_input;
 temp_loop_times=g_user_input_time;
 fflush(stdin);
 while(temp_loop_times>0){
 
  fflush(stdin);
   if(_kbhit())//if user inputed something
    {user_input=getch();
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
	{sleep(1);
	 temp_loop_times--;
	 }
  
  }//while end
 
} 

enum Lengthen_Direction get_lengthen_direction()
{if(g_head_dog_pointer->latter==0&&
    g_head_dog_pointer->formor==0)
 {return latter;}
 else if(g_head_dog_pointer->latter!=0)
 {return latter;}else{return formor;}

}

void majic_teleport()
{int aims_x,aims_y;
 enum Boolean user_confirm;
 user_confirm=false;
 if(g_MP<5)
 {  
  strcpy(g_anouncement,"时空转移失败，魔法不足");}
  else{
  g_MP=g_MP-5;
 do{ 
 printf("开始空间转移 ");
 printf("请输入要到达的x坐标");
 fflush(stdin);
 scanf("%d",&aims_x,1);
 printf("请输入要到达的y坐标 ");
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
   
   printf("输入完成"); 
 //  printf("qq %d %d ",aims_x,aims_y);
   
  
  user_confirm=wait_user_confirm("确定转移到此坐标吗？"); 
  if(user_confirm==true){printf("时空转移成功，按任意方向键继续");} 
  }while(user_confirm!=true);
   //if end 
 }//else end	
}// function end 

void majic_u_turn()
{if(g_MP>=1)
  {g_MP-=1;
   queue_u_turn();
   g_move_direction=stay; 
  printf("调头成功，耗费1点魔法, 从新输入方向继续游戏");getch();    
  }
}

void majic_clean_all_brick()
{enum Boolean user_confirm;
 if(g_MP>=50)
 { user_confirm=wait_user_confirm("终极大招会耗费全部魔法和血量，确定要释放吗？");
  if(user_confirm==true)
   {g_MP=0; g_HP=1;
    g_object_data_recorder.delete_a_class(brick);
    printf("大招释放完成，HP MP耗尽,按下任意键继续游戏\n");
	getch(); 
   }//user confirm if end
   	else{ strcpy(g_anouncement,"魔法不足，放不了终极大招"); 
   
   }//user confirm else end
 }else{
 strcpy(g_anouncement,"魔法不足50，放不了终极大招");
  }//g_MP if  end
  
	
}


void majic_slow_down()
{ if(g_MP>=10)
  {g_MP-=10;
   g_user_input_time+=300;
   printf("减速成功,输入时间增加0.3秒 按任意键继续");
   getch();
  }else{
   printf("魔法不足,无法减速 任意键继续");
   getch();
  }
  
	
}
 
 void majic_accelerate()
 { g_user_input_time-=500;
	printf("加速成功，输入时间减少0.5秒，祝好运，按任意键继续 ");
	getch(); 
  }
 
 void majic_heal()
 {if(g_MP>=4)
   {g_MP-=4;
    g_HP+=3;
	printf("成功恢复3点HP，消耗4点魔法,按任意键继续" );
	getch(); 
  }else{
  printf("成功恢复3点HP,按任意键继续" );
  getch(); 
 }//else end 
 }
 
 
 enum Boolean wait_user_confirm(char * message)
 {char user_input;
 printf("确认："); 
  printf("%s",message);

 while(true){
  printf("确认请输入Y回车，否则请输入N回车");
  fflush(stdin); 
  scanf("%c",&user_input,1);
  fflush(stdin);
  if(user_input=='y'||user_input=='Y')
   {
  
	return true;
   
   }else if(user_input=='n'||user_input=='N')
   {
  
   return false;}
    else{printf("输入有误，请重新输入");}
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
dog_manager.queue_u_turn         =&queue_u_turn;                 ;
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

 
