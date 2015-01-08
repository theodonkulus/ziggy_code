// movement.c
// Jan 3 2014
//  Theo Themistokleous
//Used to define movements for this robot
//All movement functions of robot go in and are called from here

#include "movement.h"
#include "pwm.h"

static uint16 a, b, c, d = 0; //used for motor position

void init_movement(void)
{ 	 //Put servos to neutral
	 uint16 neut_ticks =  degrees_to_ticks(90);
	 Configure_TPM0(SERVO_PERIOD, neut_ticks, neut_ticks, neut_ticks, neut_ticks);
	 NEUTRAL_POSITION;
}

void test_action(const char ch)
{
	 unsigned int i    = 0; //used for delays
	 switch(ch)
	 {
		 case 0x30:
			  a = b = c = d = 90;
				RIGHT_HIP(90);
				LEFT_HIP(90);
				LEFT_ANKLE(90);
				RIGHT_ANKLE(90);
				printf("\n\r\n\r*** Neutral position ***  %d %d %d %d\n\r", a, b, c, d);
				break;
		 case 0x31:
				c -= 5;
				RIGHT_ANKLE(c);
				printf("\n\r\n\r*** a right ankle move out ***  %d %d %d %d\n\r", a ,b, c, d);
				break;
		 case 0x32:
				d += 5;
				LEFT_ANKLE(d);
				printf("\n\r\n\r*** a left ankle move out***  %d %d %d %d\n\r", a, b, c, d);
				break;
		 case 0x33:
				a += 5;
				RIGHT_HIP(a);
				printf("\n\r\n\r*** a right hip move out***  %d %d %d %d\n\r", a ,b, c, d);
				break;
		 case 0x34:
				b -= 5;
				LEFT_HIP(b);
				printf("\n\r\n\r*** a left hip move out ***  %d %d %d %d\n\r", a, b, c, d);
				break;
		 case 0x35:
				c += 5;
				RIGHT_ANKLE(c);
				printf("\n\r\n\r*** a right ankle move in ***  %d %d %d %d\n\r", a ,b, c, d);
				break;
		 case 0x36:
				d -= 5;
				LEFT_ANKLE(d);
				printf("\n\r\n\r*** a left ankle move in ***  %d %d %d %d\n\r", a, b, c, d);
				break;
		 case 0x37:
				a -= 5;
				RIGHT_HIP(a);
				printf("\n\r\n\r*** a right hip move in ***  %d %d %d %d\n\r", a ,b, c, d);
				break;
		 case 0x38:
				b += 5;
				LEFT_HIP(b);
				printf("\n\r\n\r*** a left hip move in ***  %d %d %d %d\n\r", a, b, c, d);
				break;
		 case 0x71: 
				RIGHT_HIP(120);
				LEFT_HIP(120);
				//LEFT_ANKLE(140);
				//RIGHT_ANKLE(60);
				printf("\n\r\n\r Standing on right leg \n\r");
				break;
		 case 0x77: 
				RIGHT_HIP(60);
				LEFT_HIP(60);
				//LEFT_ANKLE(30);
				//RIGHT_ANKLE(120);
				printf("\n\r\n\r Standing on left leg \n\r");
				break;
		 case 0x61:
			 c=d=125;
			 parallel_ankle_shift(c);
		 	 while(i<1200000){i++;}
				i=0;
		   LEFT_ANKLE(90);
			 printf("\n\r\n\r Move ankles to land on left leg %d %d %d %d\n\r", a, b, c, d);
			 break;
		 case 0x73:
			 c=d= 55;
			 parallel_ankle_shift(c);
		   while(i<1200000){i++;}
			 i=0;
		   RIGHT_ANKLE(90);
			 printf("\n\r\n\r Move ankles to be on right leg %d %d %d %d\n\r", a, b, c, d);
			 break;
		 case 0x67:
			 c-= 5;
		   d-= 5;
		   parallel_ankle_shift(c);
			 printf("\n\r\n\r Move ankles towards left %d %d %d %d\n\r", a, b, c, d);
			 break;
		 case 0x68:
			 c+= 5;
		   d+= 5;
		   parallel_ankle_shift(c);
			 printf("\n\r\n\r Move ankles towards right %d %d %d %d\n\r", a, b, c, d);
			 break;
		 case 0x6A:
				printf("\n\r\n\r*** Jump!\n\r");
				LEFT_ANKLE(170);
				RIGHT_ANKLE(10);
				while(i<400000){i++;}
				i=0;
				LEFT_ANKLE(90);
				RIGHT_ANKLE(90);
				break;
		 default:
				break;
	 }
}

//DOUBLE servo movements
void parallel_hips_shift(uint16 degrees)
{
	LEFT_HIP(degrees);
	RIGHT_HIP(degrees);
}

void parallel_ankle_shift(uint16 degrees)
{
	LEFT_ANKLE(degrees);
	RIGHT_ANKLE(degrees);
}

void cross_hips_shift(uint16 degrees)
{
	LEFT_HIP(degrees);
	RIGHT_HIP(180-degrees);
}

void cross_ankle_shift(uint16 degrees)
{
	LEFT_ANKLE(degrees);
	RIGHT_ANKLE(180-degrees);
}

//Walk functionality
void walk_forward(movement_state_t * move_state)
{

}

void walk_backward(movement_state_t * move_state)
{

}


void walk_left(movement_state_t * move_state)
{

}

void walk_right(movement_state_t * move_state)
{

}

