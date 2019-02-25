/*
 * scheduleer.c
 *
 * Created: 2/23/2019 5:22:08 PM
 *  Author: AVE-LAP-063
 */ 

#include "scheduleer.h"

 volatile static uint8 flagcheck=0;
 struct My_struct Schedular_Struct[max_size];
 static volatile uint8 k=ZERO;
 static volatile sint8 remo=Negative_One;

/*************************flagtimer*********************
*Parameters :
*           I/P:void
*           O/P:void
*           I/o:void
*Return:void
*Description: to set flagcheck that execute the tasks at particular time 


********************************************************/
void flagtimer(){
	
	flagcheck = ONE; /* this to check the tick of the isr*/
	
}
/*************************TTC_SCHEDULAR*********************
*Parameters :
*           I/P:void
*           O/P:void
*           I/o:void
*Return:void
*Description: TO MANGE the sequence of tasks  this function entered every tick of isr


********************************************************/

void TTC_SCHEDULAR ()
	{
	while(1)
	{
		
		if(flagcheck==ONE)
		{
			flagcheck=ZERO; /* reset the flag for the nxt tick */

			Remaining(); 
		}/*if(flagcheck==ONE)*/
	}
}

/*************************scheduler_Add_Task(void (*ptr)(void))*********************
*Parameters :
*           I/P:void (*ptrf)(void)  THIS IS POINTER TO FUNCTION INITIALIZED BY MAIN
*           O/P:void
*           I/o:void
*Return:void
*Description: THIS IS USED IF THE USER WANT TO INTIALIZE ONLY THE APIS IN STORY ONE 

********************************************************/
uint8 scheduler_Add_Task(void (*ptr)(void))
{
	
static volatile uint16 Index=LOW;	
	if (Index<max_size){
	arr_empty[Index]=ptr; /*assigning the function called by the user*/
		Index++;
	return ONE;	
	                 }
	else {	
		return ZERO;
	     }	
}

/*************************Scheduler_init_start ()*********************
*Parameters :
*           I/P:void
*           O/P:void
*           I/o:void
*Return:void
*Description: To call the Setcallback function that will initialize the call back

********************************************************/



void Scheduler_init_start ()
{
	Set_CallBack(flagtimer); /*to set the callback function*/
	
}

/*************************schedulerStart()*********************
*Parameters :
*           I/P:void
*           O/P:void
*           I/o:void
*Return:void
*Description: To initialize the timer setting and handle the tasks

********************************************************/

void schedulerStart ()
{
	 arrange_tasks(); /*this api is to arrange tasks according to priority order */
	timer0_init(); /* To initialize the timer setting  */
	TTC_SCHEDULAR (); /* to handle the tasks*/
}

/*************************add_func(void (*ptrf)(void),uint16 PERIOD)*********************
*Parameters :
*           I/P:void (*ptrf)(void)  THIS IS POINTER TO FUNCTION INITIALIZED BY MAIN 
*           O/P:void
*           I/o:void
*Return:void
*Description: TO FILL THE ARRAY OF STRUCTURE WITH USER IT'S REQUIRED FROM THE USER TO DETERMINE  THE FUNCTION AND ITS PERIOD

********************************************************/
uint8 add_func(void (*ptrf)(void),uint16 PERIOD,uint8 prio)
{ 
	if (k<max_size)
	{
  Schedular_Struct[k].Ptr2func=ptrf;
  Schedular_Struct[k].Task_Periodicty=PERIOD;
   Schedular_Struct[k].priority=prio;
  Schedular_Struct[k].Remaining_Ticks=PERIOD; /* initializing the remaining to the period*/
  k++;
  return (TRUE);
	}
	else{
			return (FALSE);
	 /*if the user enter more than the allowed tasks */
         }
}

/*********************************************Remaining*********************
*Parameters :
*           I/P:void 
*           O/P:void
*           I/o:void
*Return:void
*Description: TO CHECK  IF THE PERIOD OF THE FUNCTION LASTS OR NOT IF THE REMAINING TIME IS ZERO TASK IS EXCUTED

********************************************************/
void Remaining()
{
	uint8 r=ZERO;
	for (r=ZERO;r<k;r++)
	{
	  if(Schedular_Struct[r].Remaining_Ticks==ZERO) /*if the period of the taks end */
	  {  
	Schedular_Struct[r].Ptr2func();  /*execute the task */
	Schedular_Struct[r].Remaining_Ticks=Schedular_Struct[r].Task_Periodicty;
	  }
	  else
	   {
		  Schedular_Struct[r].Remaining_Ticks--;	 /*this command indicates that ever tick the remaining time decrease by one */	  
	   }	  	
    }
}
 
/*********************************************arrange_tasks*********************
*Parameters :
*           I/P:void
*           O/P:void
*           I/o:void
*Return:void
*Description: TO arrange tasks according to the priority order

********************************************************/ 
 
 void arrange_tasks()
 { 	 
	 uint8 r=ZERO,j=ZERO;
	 struct My_struct temp;
	 for (r=ZERO;r<k;r++)
	 { 
		 for (j = ZERO; j < k-r-ONE; j++)
		 {
			 if ( Schedular_Struct[j].priority >  Schedular_Struct[j+ONE].priority) /*check the priority from the user */
			 {
				 
  /****************************Swap the tasks according to priority *********************/
				 temp = Schedular_Struct[j];
				 Schedular_Struct[j] =  Schedular_Struct[j+1];
				 Schedular_Struct[j+ONE]=temp;
			 } 
		 }
	 } 
 }
 /*********************************************scheduler_Remove_Task*********************
 *Parameters :
 *           I/P:(*ptrf)
 *           O/P:void
 *           I/o:void
 *Return:void
 *Description: To remove a specific task given by the user the algorithm of remove is to remove by shifting overwriting 

 ********************************************************/
void scheduler_Remove_Task(void (*ptrf)(void))

{	
 uint8 r=ZERO; 	
 for (r=ZERO;r<k;r++)
    {
		 if ( Schedular_Struct[r].Ptr2func == ptrf)
		 {
			 remo=r;  /*get the index of the task required to remove */
			 break;	 /*break when found the task required to remove*/
		 }
	 }
	if (remo!=Negative_One)  /*check that the function that user enter to remove is already exist or to check that function call remove or not */
	{
			for (r=remo;r<k;r++)
	        {
		Schedular_Struct[r].Ptr2func=Schedular_Struct[r+ONE].Ptr2func; /*shifting and overwriting */
	        }	
	k--;  /*global index indicating maximum tasks you can call */
    }
	
} 