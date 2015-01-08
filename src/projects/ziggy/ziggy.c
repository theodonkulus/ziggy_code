/*
 * File:		ziggy.c
 * Purpose:		Main process
 *
 */

#include "common.h"
#include "movement.h"

#ifdef CMSIS
#include "start.h"
#endif 
/********************************************************************/
int main (void)
{
  char ch = 0x00;
  movement_state_t position;
  memset(&position, 0, sizeof(position));
	    
#ifdef CMSIS  // If we are conforming to CMSIS, we need to call start here
    start();
#endif
        
	printf("\n\r\n\r*** Ziggy v0.1 ***\n\r");
	init_movement();
	while(1)
	{
		if(char_present()) {
		  ch = in_char();
      test_action(ch);
		  out_char(ch);
	  }			
	} 
}
/********************************************************************/
