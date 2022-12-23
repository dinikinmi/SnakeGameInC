#include "Brick_Manager.h"

void handle_hitting_event(struct Brick * hitting_brick)
{int left_HP;
 Sleep(500);
  g_HP=g_HP-hitting_brick->hardness;
 if(g_HP>0)
 { printf("碰上砖头，血量减少%d 任意键继续",hitting_brick->hardness);
 getch(); 
  (*g_object_data_recorder.delete_an_object)((void*)hitting_brick);
 }else
 {printf("你被撞死了 %d ",hitting_brick->hardness);
  getch(); 
  
 g_game_over=true;}		
}

void  make_a_wall(int x_start,int y_start,
                  int x_end,  int y_end)
{int new_x,new_y,hardness;
 new_x=x_start;
 new_y=y_start;
while(new_x!=x_end || new_y!=y_end)
{
 hardness=rand()%9;

 (*g_brick_manager.make_a_brick)(new_x,new_y,hardness);
 g_data_proccessor.calculate_next_xy_by_vector
  (new_x,new_y,x_end,y_end,&new_x,&new_y);
}//while end
}//buidl a wall end


void make_4_wall()
{
(*g_brick_manager.make_a_wall)(0,0,0,y_asix_length-1);//left wall

 (*g_brick_manager.make_a_wall)
 (x_asix_length-1,0,x_asix_length-1,y_asix_length-1);//right wall
 
 (*g_brick_manager.make_a_wall)
 (0,1,x_asix_length-1,0);//uppper wall


 (*g_brick_manager.make_a_wall)
 (0,y_asix_length-1,x_asix_length-1,y_asix_length-1);//down wall
 
}


struct Brick * make_a_random_brick()
{struct Brick * brick_pointer ;
int x,y,hardness;
 x=rand()%x_asix_length;
 y=rand()%y_asix_length;
 hardness=rand()%10;
 brick_pointer=make_a_brick(x,y,hardness);
 return brick_pointer; 
}



struct Brick * make_a_brick(int x,int y , int hardness)
{struct Brick * brick_pointer=
(struct Brick *)malloc
(sizeof(struct Brick));
 brick_pointer->x=x;
 brick_pointer->y=y;
 brick_pointer->hardness=hardness;
(g_object_data_recorder.add_new_object)((void*)brick_pointer,brick,x,y);
 return brick_pointer;
}







struct Brick_Manager make_brick_manager()
{struct Brick_Manager brick_manager;

 brick_manager.make_4_wall =&make_4_wall;
 brick_manager.make_a_wall =&make_a_wall;
 
 brick_manager.make_a_brick =&make_a_brick;
 brick_manager.make_a_random_brick=&make_a_random_brick;                         
 brick_manager.handle_hitting_event
             =&handle_hitting_event;	
               
 return brick_manager;
}

