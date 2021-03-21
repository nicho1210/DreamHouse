#include <wiringPi.h>
#include <stdio.h>
#include <string.h>
#include "motor.h"
#include "light_detect.h"
#include "outsidebrightness.h"

#define MOTOR_COUNT     3500

int isdown = 0;

void SetUp (void){
	int run;
	if (isdown == 0){
		return;
	}
	for (run = 0; run < MOTOR_COUNT; run++){
		MotorSpeed (-0.5);
	}
	isdown = 0;
}	


void SetDown (void){
	int run;
	if (isdown == 1){
		return;
	}
	for (run = 0; run < MOTOR_COUNT; run++){
		MotorSpeed (0.5);
	}
	isdown = 1;
}	

int OutLightFlag(){
	int olf;
	olf = outlight();
	if(olf <= 0xf0){
		olf = 1;
	} else {
		olf = 0;
	}
	return olf;
}


int main (int argc, char *argv[]) {
	int ol;
	int il;

	if (wiringPiSetupGpio() == -1) {
		printf ("Failed\n");
		return 1;
	}

	while(1) {
		ol = OutLightFlag();
		il = lightdetect();
		printf("ol = %d  il = %d\n", ol, il);
		if (ol > il){
			SetUp();
		} else if(il > ol){
			SetDown();
		} else if(il & ol){
			SetUp();
		} 
	}


		
	return 0;	
}


