//#include "gpio.h"
#include "gpio.c"
#include "race.c"




	int main(void){
    PortF_Init();
    EdgeCounter_Init();           // initialize GPIO Port F interrupt
    TExaS_Init(SSI0_Real_Nokia5110_Scope);  // set system clock to 80 MHz
    Random_Init(1);
		Random_Init(NVIC_ST_CURRENT_R);
		EnableInterrupts();
		ADC_Init();
    Nokia5110_Init();
	
		v1 = CARSH, v2 = - CARSH - 4 ;   // difference between rows 22 pixel
		h = 0;
		r1 = 1;
		r2 = 12;
		x = 0; 
		flag1 = 0;
		flag2 = 0;
		lives = 3;
	
	
  while(1){
		


		if(v1 > 48){ 
		  x ++,r1 =  Random32()%14, flag1 = 0;
			if(v2 > 34) v1 = CARSH;
			else v1 = v2 - 24 ;
		}
		// for new random number and restart
		if (v2 > 48){ 
			x ++,r2 =  Random32()%14, v2 = 10, flag2 = 0;  
			if(v1 > 34) v2 = CARSH;
			else v2 = v1 - 24;
		}
		// for new random number and restart
		
				if((ADC0_RIS_R & (1 << 3)) == (1 << 3)){ // if third bit is set
			ADC0_ISC_R  |= (1<<3);  // third bit = 1
			addData = ADC0_SSFIFO3_R;
		}
		h = (addData * (63-CARSW))/4095;
		
			Enemies(h,v1,v2,r1,r2,lives);
		
			
		
			if(
						!((r1 & (1<<0)) && (r2 & (1<<0)))
						&& !((r1 & (1<<1)) && (r2 & (1<<1)))
						&& !((r1 & (1<<2)) && (r2 & (1<<2)))
						&& !((r1 & (1<<3)) && (r2 & (1<<3)))	
						&& ((r1 | r2) != 15) && flag1 == 0 && flag2 == 0){ 
				
				if(v1 <= v2) flag1 = 1;
				if(v1 > v2) flag2 = 1;	
		} 
			 v1 += (x/15 + 1) + flag1; 
			 v2 += (x/15 + 1) + flag2; 
	
			Delay100ms(5);
		
		
		
		if(
				 ((v1 > 38) && (((h < 49 && h >= 41) && r1 & (1<<0)) || ((h < 41 && h >=25) && r1 & (1<<1)) || ((h < 25 && h >= 9) && r1 & (1<<2)) || ((h < 9 && h >= 0) && r1 & (1<<3))))
			|| ((v2 > 38) && (((h < 49 && h >= 41) && r2 & (1<<0)) || ((h < 41 && h >=25) && r2 & (1<<1)) || ((h < 25 && h >= 9) && r2 & (1<<2)) || ((h < 9 && h >= 0) && r2 & (1<<3))))){
			
						if(lives != 1){ 
						Delay100ms(30); 
						lives --; 
						h = 40;
						v1 = CARSH; 
						v2 = - CARSH - 4; 
					}
					else {
						Nokia5110_Clear();
						Nokia5110_SetCursor(1, 1);
						Nokia5110_OutString("GAME OVER");
						Nokia5110_SetCursor(1, 2);
						Nokia5110_OutString("your score: ");
						Nokia5110_SetCursor(1, 3);
						Nokia5110_OutUDec(x);
						Nokia5110_SetCursor(1, 4);
						Nokia5110_OutString("Q or A");

						break;
						}
			
		}
		
		
			

	}
}



