#include <wiringPi.h>
#include <stdio.h>

#define GPIO_pin	21
#define END_COUNT	10
#define DEBOUNCE    10

int lightdetect () {
	int debounce;
	int flag = 1;//, count = 0;
	int inputStatus = 0;
	
	
	//printf ("Red Light\n");
	
	pinMode (GPIO_pin, INPUT);
	
//	while (1) {
		for (debounce = 0; debounce < DEBOUNCE; debounce++) {
			delay (1);
			inputStatus = digitalRead (GPIO_pin);
		}
		if (inputStatus) {
			if (flag == 0) {
				flag = 1;
				//count++;
				//printf ("Dark [%d]!!\n", count);
				return 0;
			}
		} else {
			if (flag) {
				flag = 0;
				//count++;
				//printf ("Light [%d]!!\n", count);
				return 1;
			}
		}
		
//		if (count == END_COUNT) {
//			break;
//		}
//	}
	return 0;	
}
