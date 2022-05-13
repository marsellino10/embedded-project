//#include "gpio.h"
#include "gpio.c"
#include "race.c"




void Timer2_Init(unsigned long period);
void Delay100ms(unsigned long count);
void ADC_Init(void);
int TimerCount, Semaphore;
int delay;
int m;
volatile int addData;
void ADC_Init(void){
	
	SYSCTL_RCGCADC_R |= (1<<0);
	SYSCTL_RCGCGPIO_R|= (1<<4)
												|(1<<5);
	delay=SYSCTL_RCGCGPIO_R;
	
	GPIO_PORTE_AFSEL_R |=(1<<2);

	GPIO_PORTE_DEN_R &= ~(1<<2);
	
	GPIO_PORTE_AMSEL_R |= (1<<2);
	
	ADC0_ACTSS_R &= ~(1<<3);
	
	ADC0_EMUX_R = (0XF<<12);
	
	
	ADC0_SSMUX3_R = 1;
	
	ADC0_SSCTL3_R |=(1<<1)
								|(1<<2);
		
	ADC0_IM_R |=(1<<2);
	
	ADC0_RIS_R |=(1<<3);
	
	ADC0_ACTSS_R |= (1<<3);	

  NVIC_EN2_R |= (1<<3);
	
}

int main(void){
    PortF_Init();
    EdgeCounter_Init();           // initialize GPIO Port F interrupt
    TExaS_Init(SSI0_Real_Nokia5110_Scope);  // set system clock to 80 MHz
    Random_Init(1);
		Random_Init(NVIC_ST_CURRENT_R);
	EnableInterrupts();
	
		ADC_Init();
    Nokia5110_Init();
	
		v1 = CARH, v2 = - CARH - 2 ;
		h = 0;
		r1 = 1;
		r2 = 12;
		x = 0; 
		flag1 = 0;
		flag2 = 0;
  while(1){
		

	if((ADC0_RIS_R & (1 << 3)) == (1 << 3)){ // if third bit is set
			ADC0_ISC_R  |= (1<<3);  // third bit = 1
			addData = ADC0_SSFIFO3_R;
		}
		
		
		
		h = (addData * (83-CARW))/4095;
		
		
		if(v1 > 48){ 
		  x ++,r1 =  Random32()%14, flag1 = 0;
			if(v2 > 27) v1 = CARH;
			else v1 = v2 - 22;
		}
		// for new random number and restart
		if (v2 > 48){ 
			x ++,r2 =  Random32()%14, v2 = 10, flag2 = 0;  
			if(v1 > 27) v2 = CARH;
			else v2 = v1 - 22;
		}
		// for new random number and restart
			Enemies(h,v1,v2,r1,r2);
		
			
		
			if(
						!((r1 & (1<<0)) && (r2 & (1<<0)))
						&& !((r1 & (1<<1)) && (r2 & (1<<1)))
						&& !((r1 & (1<<2)) && (r2 & (1<<2)))
						&& !((r1 & (1<<3)) && (r2 & (1<<3)))	
						&& ((r1 | r2) != 15) && flag1 == 0 && flag2 == 0){ 
				
				if(v1 <= v2) flag1 = 1;
				if(v1 > v2) flag2 = 1;	
		} 
			 v1 += (x/10 + 1) + flag1; 
			 v2 += (x/10 + 1) + flag2; 
	
			Delay100ms(1);
		
		if(v1 > 40){
		
			if (
				(h == 48 && r1 & (1<<0)) || ((h < 48 && h >=32) && r1 & (1<<1)) || ((h < 32 && h >= 16) && r1 & (1<<2)) || ((h < 16 && h >0) && r1 & (1<<3))){
				
					//Delay100ms(10);
					Nokia5110_Clear();
					Nokia5110_SetCursor(1, 1);
					Nokia5110_OutString("GAME OVER");
					Nokia5110_SetCursor(1, 2);
					Nokia5110_OutString("your score: ");
					Nokia5110_SetCursor(1, 3);
					Nokia5110_OutUDec(x);
					Nokia5110_SetCursor(1, 4);
				  Nokia5110_OutString("Q or A");
					Delay100ms(1);
					break;
		}
	}
		else if(v2 > 40){
			
			if (
				(h == 48 && r2 & (1<<0)) || ((h < 48 && h >=32) && r2 & (1<<1)) || ((h < 32 && h >= 16) && r2 & (1<<2)) || ((h < 16 && h >0) && r2 & (1<<3))){
					//Delay100ms(10);
					Nokia5110_Clear();
					Nokia5110_SetCursor(1, 1);
					Nokia5110_OutString("GAME OVER");
					Nokia5110_SetCursor(1, 2);
					Nokia5110_OutString("your score: ");
					Nokia5110_SetCursor(1, 3);
					Nokia5110_OutUDec(x); 
					Nokia5110_SetCursor(1, 4);
				  Nokia5110_OutString("Q or A");
					Delay100ms(1);
					break;
			}	
		}
		

	}
}






// You can use this timer only if you learn how it works
void Timer2_Init(unsigned long period){ 
  unsigned long volatile delay;
  SYSCTL_RCGCTIMER_R |= 0x04;   // 0) activate timer2
  delay = SYSCTL_RCGCTIMER_R;
  TimerCount = 0;
  Semaphore = 0;
  TIMER2_CTL_R = 0x00000000;    // 1) disable timer2A during setup
  TIMER2_CFG_R = 0x00000000;    // 2) configure for 32-bit mode
  TIMER2_TAMR_R = 0x00000002;   // 3) configure for periodic mode, default down-count settings
  TIMER2_TAILR_R = period-1;    // 4) reload value
  TIMER2_TAPR_R = 0;            // 5) bus clock resolution
  TIMER2_ICR_R = 0x00000001;    // 6) clear timer2A timeout flag
  TIMER2_IMR_R = 0x00000001;    // 7) arm timeout interrupt
  NVIC_PRI5_R = (NVIC_PRI5_R&0x00FFFFFF)|0x80000000; // 8) priority 4
// interrupts enabled in the main program after all devices initialized
// vector number 39, interrupt number 23
  NVIC_EN0_R = 1<<23;           // 9) enable IRQ 23 in NVIC
  TIMER2_CTL_R = 0x00000001;    // 10) enable timer2A
}
void Timer2A_Handler(void){ 
  TIMER2_ICR_R = 0x00000001;   // acknowledge timer2A timeout
  TimerCount++;
  Semaphore = 1; // trigger
}
void Delay100ms(unsigned long count){unsigned long volatile time;
  while(count>0){
    time = 727240;  // 0.1sec at 80 MHz
    while(time){
	  	time--;
    }
    count--;
  }
}
