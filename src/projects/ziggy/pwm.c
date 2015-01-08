// pwm.c
// Jan 3 2014
// Theo Themistokleous
//Low level setup and movement control via PWM for ARM freedom board
//Channels are setup to be controlled individually
//If you want to reuse this module for other ports, you must modify Configure_TPM0()

#include "pwm.h"

uint16 pulse_width_in_ticks(uint16 period, uint16 duty_cycle)
{//Duty cycle in terms of ticks
		return (period * duty_cycle) / 100;
}

void Configure_TPM0(uint16 period, uint16 Ch1, uint16 Ch2, uint16 Ch3, uint16 Ch4)
{
    // Enable the Clock gate to the MODULE!!
    SIM_SCGC6 |= SIM_SCGC6_TPM0_MASK;
    SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK | SIM_SCGC5_PORTC_MASK;
    
    // Ensure that the module is disabled first
    TPM0_SC = 0x00;
           
    //  PIN CONFIGURATION
    // Configure PTD2 and 3 for TPM functionality
    PORTD_PCR2 = PORT_PCR_MUX(4); // D2
    PORTD_PCR3 = PORT_PCR_MUX(4); // D3
	  PORTD_PCR4 = PORT_PCR_MUX(4); // D4
    PORTC_PCR9 = PORT_PCR_MUX(3); //C9
	
    // CLOCK CONFIGURATION
    // Enable the IRCLK
    MCG_C1 |= MCG_C1_IRCLKEN_MASK;
    // Set the IRCLK to fast clock
    MCG_C2 |= MCG_C2_IRCS_MASK;
    
    // Set the TPM clock source to the IRCLK
    SIM_SOPT2 &= ~SIM_SOPT2_TPMSRC_MASK;
    SIM_SOPT2 |= SIM_SOPT2_TPMSRC(3);
    
    // Select a Prescale value of 2 to get a 1us resolution
    TPM0_SC |= TPM_SC_PS(1);
    
    //CHANNEL CONFIGURATIONS   
    // Configure module registers
    TPM0_C2SC = TPM_CnSC_CHF_MASK;
    TPM0_C3SC = TPM_CnSC_CHF_MASK;
    TPM0_C4SC = TPM_CnSC_CHF_MASK;
		TPM0_C5SC = TPM_CnSC_CHF_MASK;

    // Setup TPM0 Channels for Edge aligned PWM
    TPM0_C2SC = (TPM_CnSC_MSB_MASK | TPM_CnSC_ELSB_MASK);
		TPM0_C3SC = (TPM_CnSC_MSB_MASK | TPM_CnSC_ELSB_MASK);
    TPM0_C4SC = (TPM_CnSC_MSB_MASK | TPM_CnSC_ELSB_MASK);
		TPM0_C5SC = (TPM_CnSC_MSB_MASK | TPM_CnSC_ELSB_MASK);

    // Initialize Channel value registers
    TPM0_C2V = Ch1;
    TPM0_C3V = Ch2;
    TPM0_C4V = Ch3;
		TPM0_C5V = Ch4;
		
    // Configure the MOD register
    TPM0_MOD = period;
    TPM0_CNT = 0;
    
    // Enable TPM0 IRQ (IRQ #17)
    //enable_irq(17);
    
    // Finally Enable the TPM module
    TPM0_SC |= TPM_SC_CMOD(1);
}

uint16 degrees_to_ticks(uint16 degrees)
{
	 if(degrees > 180) {
	   return SERVO_MAX;	
	 }
	 return ((10*degrees) + SERVO_MIN);
}

void ch1_move(uint16 degrees)
{ //servo has 0 degrees at 500us , 180 at 240. y = 10x + 500
	 uint16 ticks_to_motors = 0;
	
	 if(degrees > 180)
	 {
	    ticks_to_motors = SERVO_MAX;
	 } else {
      ticks_to_motors = ((10*degrees) + SERVO_MIN);
	 }
	 TPM0_C3V = ticks_to_motors;
}

void ch2_move(uint16 degrees)
{ //servo has 0 degrees at 500us , 180 at 240. y = 5x + 500
	 uint16 ticks_to_motors = 0;
	
	 if(degrees > 180)
	 {
	    ticks_to_motors = SERVO_MAX;
	 } else {
      ticks_to_motors = ((10*degrees) + SERVO_MIN);
	 }
	 TPM0_C2V = ticks_to_motors;
}

void ch3_move(uint16 degrees)
{ //servo has 0 degrees at 500us , 180 at 240. y = 5x + 500
	 uint16 ticks_to_motors = 0;
	
	 if(degrees > 180)
	 {
	    ticks_to_motors = SERVO_MAX;
	 } else {
      ticks_to_motors = ((10*degrees) + SERVO_MIN);
	 }
	 TPM0_C4V = ticks_to_motors;
}

void ch4_move(uint16 degrees)
{ //servo has 0 degrees at 500us , 180 at 240. y = 5x + 500
	 uint16 ticks_to_motors = 0;
	
	 if(degrees > 180)
	 {
	    ticks_to_motors = SERVO_MAX;
	 } else {
      ticks_to_motors = ((10*degrees) + SERVO_MIN);
	 }
	 TPM0_C5V = ticks_to_motors;
}
