#pragma config(Motor,  port2,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,            ,             tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,            ,             tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//#include "vex_competition_include.c"


void moveForward(int speed){
	setMotor(port2, -1 * speed);
	setMotor(port3, speed);
	forward(speed);
	wait(1);
	stopMotor(port2);
	stopMotor(port3);
}

void moveBackward(int speed){
	setMotor(port2, -1 * speed);
	setMotor(port3, speed);
	forward(-1 * speed);
	wait(1);
	stopMotor(port2);
	stopMotor(port3);
}
void right(int speed){
	setMotor(port2, speed);
	forward(speed);
	stopMotor(port2);
}

void left(int speed){
	setMotor(port3, speed);
	forward(speed);
	stopMotor(port3);
}

void lift(int speed){
	setMotor(port4, speed);
	forward(speed);
	stopMotor(port4);
}

void freeze(){
	stopMotor(port2);
	stopMotor(port3);
}


task main(){
	// port2 and port3 are for the motors
	// port4 is to lift the claw
	// port5 is to open and close the claw
	bool forb = true;
	bool lorr = true;
	bool uord = true;
	while(1==1){

		//change modes
		if(vexRT[Btn8U] == 1){
			forb = true;
		}
		if(vexRT[Btn8D] == 1){
			forb = false;
		}

		if(vexRT[Btn8R] == 1){
			lorr = true;
		}
		if(vexRT[Btn8L] == 1){
			lorr = false;
		}

		if(vexRT[Btn5U] == 1){
			uord = !(uord);
		}

		//forward and backward
		if(vexRT[Ch2] > 0&& forb){
			int i = (int)((127 / 105)*vexRT[Ch2]);
			moveForward(i);

		}
		if(vexRT[Ch2] > 0&& forb == false){
			int i = (int)((127 / 105) * vexRT[Ch2]);
			moveBackward(i);
		}


		//turn
		if(vexRT[Ch1] > 0 && lorr == true){
			int i = (int)((127 / 105) * vexRT[Ch1]);
			right(i);
		}
		if(vexRT[Ch1] > 0 && lorr == false){
			int i = (int)((127 / 105) * vexRT[Ch1]);
			left(i);
		}


		//lift
		if(vexRT[Ch3] > 0 && uord == true){
			int i = (int)((127/105) * vexRT[Ch3]);
			lift(i);
		}
		if(vexRT[Ch3] > 0 && uord == false){
			int i = (int)((127/105) * vexRT[Ch3]);
			lift(-1*i);
		}


		//break
		if(vexRT[Btn5D] == 1){
			freeze();
		}


	}
}
