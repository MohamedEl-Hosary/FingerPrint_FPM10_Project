/*
 * LCD.c
 *
 * Created: 4/1/2018 7:36:09 PM
 *  Author: Peter
 */ 
#include "LCD.h"
static void vWrite_byte (uint8_t data);
#ifdef fBIT_MODE
void  vInit_lcd (void)
{
	SET_BIT(D4_DIR,D4);
	SET_BIT(D5_DIR,D5);
	SET_BIT(D6_DIR,D6);
	SET_BIT(D7_DIR,D7);
	SET_BIT(EN_DIR,EN);
	SET_BIT(RW_DIR,RW);
	SET_BIT(RS_DIR,RS);
	CLR_BIT (RW_port,RW);
	vWrite_inst(0x02);
	vWrite_inst(0x28);
	vWrite_inst(0x01);
	vWrite_inst(0x0c);
	vWrite_inst(0x06);
	vWrite_inst(0x80);
	_delay_ms(20);
}

static void vWrite_byte (uint8_t data)
{
	if (readbit(data,4))
	{
		SET_BIT(D4_port,D4);	
	}
	else
	{
		CLR_BIT(D4_port,D4);
	}
	if (readbit(data,5))
	{
		SET_BIT(D5_port,D5);
	}
	else
	{
		CLR_BIT(D5_port,D5);
	}
	if (readbit(data,6))
	{
		SET_BIT(D6_port,D6);
	}
	else
	{
		CLR_BIT(D6_port,D6);
	}
	if (readbit(data,7))
	{
		SET_BIT(D7_port,D7);
	}
	else
	{
		CLR_BIT(D7_port,D7);
	}
	vSend_epulse();
	if (readbit(data,0))
	{
		SET_BIT(D4_port,D4);
	}
	else
	{
		CLR_BIT(D4_port,D4);
	}
	if (readbit(data,1))
	{
		SET_BIT(D5_port,D5);
	}
	else
	{
		CLR_BIT(D5_port,D5);
	}
	if (readbit(data,2))
	{
		SET_BIT(D6_port,D6);
	}
	else
	{
		CLR_BIT(D6_port,D6);
	}
	if (readbit(data,3))
	{
		SET_BIT(D7_port,D7);
	}
	else
	{
		CLR_BIT(D7_port,D7);
	}
	vSend_epulse();
} 
void vWrite_inst (uint8_t inst)
{
	CLR_BIT (RS_port,RS);
	vWrite_byte(inst);
}
void vWrite_char (uint8_t inst)
{
	SET_BIT (RS_port,RS);
	vWrite_byte(inst);
}
void vWrite_string(unsigned char* name)
{
	uint8_t i=0;
	while (name[i]!='\0')
	{
		vWrite_char(name[i]);	
		i++;
	}
}
void vSend_epulse (void)
{
	SET_BIT(EN_port,EN);
	_delay_ms(5);
	CLR_BIT(EN_port,EN);
	_delay_ms(5);	
}

void vWrite_number(uint16_t number){
	if(number > 9999){
		uint8_t first,second,third,fourth,fifth;
		first = number/10000;
		second = (number%10000)/1000;
		third = ((number%10000)%1000)/100;
		fourth = (((number%10000)%1000)%100)/10;
		fifth = (((number%10000)%1000)%100)%10;
		vWrite_char(first | 0x30);
		vWrite_char(second | 0x30);
		vWrite_char(third | 0x30);
		vWrite_char(fourth | 0x30);
		vWrite_char(fifth | 0x30);
	}else{
		if(number > 999){
			uint8_t first,second,third,fourth;
			first = number/1000;
			second = (number%1000)/100;
			third = ((number%1000)%100)/10;
			fourth = ((number%1000)%100)%10;
			vWrite_char(first | 0x30);
			vWrite_char(second | 0x30);
			vWrite_char(third | 0x30);
			vWrite_char(fourth | 0x30);
		}else{
			if(number > 99){
				uint8_t first,second,third;
				first = number/100;
				second = (number%100)/10;
				third = (number%100)%10;
				vWrite_char(first | 0x30);
				vWrite_char(second | 0x30);
				vWrite_char(third | 0x30);
			}else{
				if(number > 9){
					uint8_t first,second;
					first = number/10;
					second = number%10;
					vWrite_char(first | 0x30);
					vWrite_char(second | 0x30);
				}else{
					vWrite_char( (uint8_t) (number|0x30) );
				}
			}
		}
	}
}


void vWrite_number_32bit(uint32_t number){
	if(number>999999999){
		uint8_t stringOfNumbers [10];
		int i =0;
		while(number != 0){
			stringOfNumbers[i] = number%10;
			number  =number/10;
			i++;
		}
		int j;
		for(j=i-1;j>=0;j--){
			vWrite_char(stringOfNumbers[j]+48);
		}
	}else{
		if(number>99999999){
			uint8_t stringOfNumbers [9];
			int i =0;
			while(number != 0){
				stringOfNumbers[i] = number%10;
				number  =number/10;
				i++;
			}
			int j;
			for(j=i-1;j>=0;j--){
				vWrite_char(stringOfNumbers[j]+48);
			}
		}else{
			if(number>9999999){
				uint8_t stringOfNumbers [8];
				int i =0;
				while(number != 0){
					stringOfNumbers[i] = number%10;
					number  =number/10;
					i++;
				}
				int j;
				for(j=i-1;j>=0;j--){
					vWrite_char(stringOfNumbers[j]+48);
				}
			}else{
				if(number>999999){
					uint8_t stringOfNumbers [7];
					int i =0;
					while(number != 0){
						stringOfNumbers[i] = number%10;
						number  =number/10;
						i++;
					}
					int j;
					for(j=i-1;j>=0;j--){
						vWrite_char(stringOfNumbers[j]+48);
					}
				}else{
					if(number>99999){
						uint8_t stringOfNumbers [6];
						int i =0;
						while(number != 0){
							stringOfNumbers[i] = number%10;
							number  =number/10;
							i++;
						}
						int j;
						for(j=i-1;j>=0;j--){
							vWrite_char(stringOfNumbers[j]+48);
						}
					}else{
						if(number>9999){
							uint8_t stringOfNumbers [5];
							int i =0;
							while(number != 0){
								stringOfNumbers[i] = number%10;
								number  =number/10;
								i++;
							}
							int j;
							for(j=i-1;j>=0;j--){
								vWrite_char(stringOfNumbers[j]+48);
							}
						}else{
							if(number>999){
								uint8_t stringOfNumbers [4];
								int i =0;
								while(number != 0){
									stringOfNumbers[i] = number%10;
									number  =number/10;
									i++;
								}
								int j;
								for(j=i-1;j>=0;j--){
									vWrite_char(stringOfNumbers[j]+48);
								}
							}else{
								if(number>99){
									uint8_t stringOfNumbers [3];
									int i =0;
									while(number != 0){
										stringOfNumbers[i] = number%10;
										number  =number/10;
										i++;
									}
									int j;
									for(j=i-1;j>=0;j--){
										vWrite_char(stringOfNumbers[j]+48);
									}
								}else{
									if(number>9){
										uint8_t stringOfNumbers [2];
										int i =0;
										while(number != 0){
											stringOfNumbers[i] = number%10;
											number  =number/10;
											i++;
										}
										int j;
										for(j=i-1;j>=0;j--){
											vWrite_char(stringOfNumbers[j]+48);
										}
									}else{
										uint8_t stringOfNumbers  = number+48;
										vWrite_char(stringOfNumbers);
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


void vGotoxy (uint8_t row,uint8_t col){
	if( (col > 15) | (col < 0) | (row > 1) | (row < 0) ){    // check boundaries
		vWrite_inst(0x02);           // go home and start from there
		int i;
		for(i=0;i<40;i++){  // move cursor right 40 steps to go to next line -> datasheet
			vWrite_inst(0x14);      // move cursor right one step
		}
		vWrite_string("Wrong boundaries");  // write error in the next line
	}
	else{
		if(row == 0){
			vWrite_inst(0x02);           // go home and start from there
			int i;
			for(i=0;i<col;i++){
			vWrite_inst(0x14);          // move cursor right one step	
			}
		}else{     // row == 1
			vWrite_inst(0x02);          // go home and start from there
			int i;
			for(i=0;i<(col + 40);i++){  // move cursor right 40 steps to go to next line -> datasheet, then move right to col
				vWrite_inst(0x14);      // move cursor right one step
			}
		}
	}
}

#endif // 4BIT_MODE