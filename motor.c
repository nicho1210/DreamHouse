#include <wiringPi.h>
#include <stdio.h>

//Initial motor parameter
#define motor_driver_time  1000

int motor_left_io[] = {12,25};
int motor_right_io[] = {13,26};

//Initial motor speed  -1.0 (Reverse) ~ 1.0 (Forward)
//float motor_speed = 0.3;

int MotorSpeed (float motor_speed) {
	int i, motor_dir;
	float j, high_single = 0.0;
	
	//printf ("Motor\n");
	
	for (i = 0; i < 2; i++) {
		pinMode (motor_left_io[i], OUTPUT);
		pinMode (motor_right_io[i], OUTPUT);
	}
	for (i = 0; i < 2; i++) {
		digitalWrite (motor_left_io[i], LOW);
		digitalWrite (motor_right_io[i], LOW);
	}
	
	//Sonar detect Loop
	//Setup motor counter and direction
	if (motor_speed >= 0) {
		high_single = motor_driver_time*motor_speed;
		motor_dir = 0;
	} else {
		high_single = motor_driver_time*-motor_speed;
		motor_dir = 1;
	}
	//motor control loop
	for (j = 0; j < motor_driver_time; j++) {
		//Setup motor control output
		if (j < high_single) {
			delayMicroseconds(1);
			digitalWrite (motor_left_io[motor_dir], HIGH);
			digitalWrite (motor_right_io[motor_dir], HIGH);
		} else {
			delayMicroseconds(1);
			digitalWrite (motor_left_io[motor_dir], LOW);
			digitalWrite (motor_right_io[motor_dir], LOW);
		}
	}
	return 0;
}

