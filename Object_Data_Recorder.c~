#include "Object_Data_Recorder.h"
 


enum Boolean whether_class_exist(enum Class checking_class)
{struct Object * checking_object_pointer;
 checking_object_pointer=g_object_link_head_pointer;
 while(checking_object_pointer!=0)
 {if(checking_object_pointer->source_object_class
                              ==checking_class)
   {return true;}else{
  checking_object_pointer=checking_object_pointer->latter;
   }//althogh this else is unesserary,but it make it readable
 }//while end 
 return false;
}


void update_screen_parttern_record()
{struct Dog * dog_pointer;
 struct Food * food_pointer;
 struct Brick * brick_pointer;
 struct Object * object_pointer;
 int x,y;
 char parttern;

 
 (*g_object_data_recorder.clean_screen_parttern_record)();
//mp value changed from here,bug 
 object_pointer=g_object_link_head_pointer;
 while(object_pointer!=0)
 { switch(object_pointer->source_object_class)
   {case dog:
   	   dog_pointer=(struct Dog *)
	   object_pointer->source_object_pointer;
      parttern=(*g_dog_manager.get_dog_parttern)(dog_pointer);
     // printf("dog test %c ",parttern);getch();
      x=dog_pointer->x; y=dog_pointer->y;
      break;		            

	case brick:
    brick_pointer=
       (struct Brick*)object_pointer->source_object_pointer;
    x=brick_pointer->x;y=brick_pointer->y;
    // itoa(brick_pointer->hardness,parttern,10);
	parttern=brick_pointer->hardness+'0';
	
  	break;
	    
	case food:                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
   	  food_pointer=
	  (struct Food *)object_pointer->source_object_pointer;
	  x=food_pointer->x; y=food_pointer->y;
      parttern=(*g_food_manager.get_food_parttern)(food_pointer);
      break;  

	default ://if the class is object
     break;
   }//switch end
   if(x>x_asix_length-1){x=x_asix_length-1;}
   if(y>y_asix_length-1){y=y_asix_length-1;}
   //to prevent from crossing the end of array
	g_screen_parttern[x][y]=parttern;

 object_pointer=object_pointer->latter;
 }  
}


void delete_an_object(void * delete_object_pointer)
{struct Object * checking_object_pointer;
 struct Object * formor_object_pointer;
 struct Object * latter_object_pointer;
 if(delete_object_pointer==0)
   {return;}
 //预防不小心传入空指针导致头指针被删除 
 checking_object_pointer=g_object_link_head_pointer;

while(checking_object_pointer!=0)
{
formor_object_pointer=checking_object_pointer->formor;
  latter_object_pointer=checking_object_pointer->latter;
 if(checking_object_pointer->source_object_pointer==delete_object_pointer) 
  {(*g_data_proccessor.clean_and_free_ram)
         (checking_object_pointer->source_object_pointer);
   (*g_data_proccessor.clean_and_free_ram)
         (checking_object_pointer);
    
	if(formor_object_pointer!=0)
    {formor_object_pointer->latter=latter_object_pointer;}
    if(latter_object_pointer!=0)
    {latter_object_pointer->formor=formor_object_pointer;}
    return;
  }//outter if
    else{checking_object_pointer=latter_object_pointer;
	 }//outter if else 
 
}//while

}//function



void delete_a_class(enum Class delete_class)
{struct Object * checking_object_pointer;
 struct Object * formor_pointer;
 struct Object * latter_pointer;
 
 checking_object_pointer=g_object_link_head_pointer;
 while(checking_object_pointer!=0)
 {printf("ss");
  formor_pointer=checking_object_pointer->formor;
  latter_pointer=checking_object_pointer->latter;
  
  if(checking_object_pointer->source_object_class==
     delete_class){//printf("ss");
	 (*g_data_proccessor.clean_and_free_ram)
	   (checking_object_pointer->source_object_pointer);
    (*g_data_proccessor.clean_and_free_ram)
	   (checking_object_pointer);
	   
	if(latter_pointer==0){return;}
	else{latter_pointer->formor=formor_pointer;}
	   
	if(formor_pointer!=0)
	{formor_pointer->latter=latter_pointer;}
 
   }//class if end
   	checking_object_pointer=latter_pointer;
 }//while end	
}


void add_new_object
(void * source_object_pointer,enum Class source_object_class)
{struct Object * checking_object_pointer;
 struct Object * new_object_pointer;
 
 new_object_pointer=(struct Object *)
                     malloc(sizeof(struct Object));
 new_object_pointer->latter=0;
 //remember to set the latter to 0,SB!! 
 //or you will get a never ending object link
 new_object_pointer->source_object_pointer
              =source_object_pointer;
 new_object_pointer->source_object_class
              =source_object_class;
checking_object_pointer=get_last_object_pointer();
 if(checking_object_pointer==0)
 {checking_object_pointer=g_object_link_head_pointer;}
  // if it return 0,means there is
  // only one head object ,no tail
 
  checking_object_pointer->latter=new_object_pointer;
  new_object_pointer->formor=checking_object_pointer;
}//function  end


void clean_screen_parttern_record()
{int x,y;

  		for(y=0;y<y_asix_length;y++){
  	 for(x=0;x<x_asix_length;x++){
	 g_screen_parttern[x][y]=' ';
  
    }//inner for
  }//outter for
  
  
}//founction end

struct Object * make_object_link()
{struct Object * head_object_pointer;
 head_object_pointer=(struct Object *)
 (malloc (sizeof(struct Object)) );
 
 head_object_pointer->source_object_pointer=0;
 head_object_pointer->source_object_class=object;
 head_object_pointer->latter=0;
 head_object_pointer->formor=0; 

 
 return head_object_pointer;
}


enum Class get_class_by_xy(int x,int y)
{struct Object * checking_object_pointer=g_object_link_head_pointer;
 struct Food * food_pointer;
 struct Brick * brick_pointer;
 struct Dog * dog_pointer; 
 while(checking_object_pointer!=0)
 { switch
 (checking_object_pointer->source_object_class)
    {case food:
      food_pointer=
	  (struct Food *)checking_object_pointer->source_object_pointer;
      if(food_pointer->x==x & food_pointer->y==y)
	   {return food;} 
	 
	 case brick:
      brick_pointer=
	  (struct Brick *)checking_object_pointer->source_object_pointer;
      if(brick_pointer->x==x & brick_pointer->y==y)
	   {return brick;} 
	 
	 
	 case dog:
      dog_pointer=(struct Dog *)checking_object_pointer->source_object_pointer;
      if(dog_pointer->x==x & dog_pointer->y==y)
	   {return dog;} 
	
	
	 default:  break;
	
	
	}//switch end
   checking_object_pointer=checking_object_pointer->latter;
 }//while end
 return nothing;								
}

struct Object * get_last_object_pointer()
{struct Object * checking_object_pointer;
  if(g_object_link_head_pointer->latter==0)
  {  
  return 0;
  }else
  {  
  checking_object_pointer=
          g_object_link_head_pointer->latter;  
  
  while(1){  
    if(checking_object_pointer->latter==0)
	 {  return checking_object_pointer;
     } else
	 {checking_object_pointer=checking_object_pointer->latter;
	
	 }//inner else end  
  }//while end
  }//outter else end
}



struct Object_Data_Recorder make_object_data_recorder()
{struct Object_Data_Recorder recorder; 
 recorder.update_screen_parttern_record
        =&update_screen_parttern_record;
 recorder.clean_screen_parttern_record=
         &clean_screen_parttern_record;
 recorder.delete_an_object  =&delete_an_object; 
 //recorder.check_class_exist =&check_class_exist;
 recorder.whether_class_exist=&whether_class_exist;
 recorder.add_new_object=&add_new_object;
 recorder.make_object_link=&make_object_link;
 recorder.delete_a_class=& delete_a_class;
// recorder.class_cornfirm_by_xy=&class_confrim_by_xy;
 recorder.get_class_by_xy=&get_class_by_xy;
 recorder.get_last_object_pointer=&get_last_object_pointer;
return recorder;
}
