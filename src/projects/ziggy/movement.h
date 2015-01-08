// movement.h
// Jan 3 2014
//  Theo Themistokleous
//Used to define movements for this robot
//Use macros to map channels to actuators and 
#ifndef __MOVEMENT_H__
#define __MOVEMENT_H__

#include "pwm.h"
//these defines NEED pwm.h
#define LEFT_HIP(x)    ch1_move(x)
#define RIGHT_HIP(x)   ch2_move(x)
#define LEFT_ANKLE(x)  ch3_move(x)
#define RIGHT_ANKLE(x) ch4_move(x)

#define NEUTRAL_POSITION test_action(0x30);

// ** Here you can see the basic steps of a walk forward
//  0) Lift to Left (Right foot off ground)
//  1) Center up Right Ankle and both Hips
//  2) Swivel hips moving right foot forward (Left Hip In, Right Hip Out)
//  3) Center left ankle putting you back on the ground
//  4) Lift to Right (Left foot off ground)
//  5) Center Left Ankle and Hips
//  6) Swivel hips moving left foot forward
//  7) Center right ankle to back on the ground
//  Note this leaves us in a left foot forward stance so the WalkStop, etc corrects that to normal position

enum direction_state_e {
   DIRECTION_STOP = 0,
   DIRECTION_FORWARD,
   DIRECTION_BACK,
   DIRECTION_LEFT,
   DIRECTION_RIGHT,
};

typedef movement_limits_s {


}

typedef movement_state_s {
   uint16 left_hip_degree;
   uint16 right_hip_degree;
   uint16 left_ankle_degree;
   uint16 right_ankle_degree;
   enum direction_state_e;
   unsigned int step_size;
}movement_state_t;

//init and test
void init_movement(void);
void test_action(const char ch);

//double servo movements
void parallel_hip_shift(uint16 degrees);
void parallel_ankle_shift(uint16 degrees);
void cross_hip_shift(uint16 degrees);
void cross_ankle_shift(uint16 degrees);

//Walk functions
void walk_forward(movement_state_t * move_state);
void walk_backward(movement_state_t * move_state);
void walk_left(movement_state_t * move_state);
void walk_right(movement_state_t * move_state);

#endif
