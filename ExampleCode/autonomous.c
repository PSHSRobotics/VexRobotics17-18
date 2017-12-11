//
// http://www.education.rec.ri.cmu.edu/fire/media/best_webinars/week5/Competition%20Code.c
// 
#pragma config(Sensor, dgtl1,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,         sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop)
#pragma config(Motor,  port6,           armMotor,      tmotorNormal, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(300)
#pragma userControlDuration(900)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
  SensorValue[rightEncoder] = 0;  //Clear the right encoder value
  SensorValue[leftEncoder] = 0;   //Clear the left encoder value

  //While the encoders have spun less than 3 rotations...
  while(SensorValue[rightEncoder] < 1080)
  {
    //Move Forward
    motor[rightMotor] = 63;
    motor[leftMotor] = 63;
  }


  //Stop for half a second
  motor[rightMotor] = 0;
  motor[leftMotor] = 0;
  wait1Msec(500);


  SensorValue[rightEncoder] = 0;  //Clear the right encoder value
  SensorValue[leftEncoder] = 0;   //Clear the left encoder value

  //While the right encoder has spun less than 1 rotation...
  while(SensorValue[leftEncoder] < 360)
  {
    //Turn Left
    motor[rightMotor] = -63;
    motor[leftMotor] = 63;
  }
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	// User control code here, inside the loop

	while (true)
	{
	  motor[leftMotor] = vexRT[Ch3];  //Set the left motor power equal to the left joystick vertical axis
    motor[rightMotor] = vexRT[Ch2]; //Set the right motor power equal to the right joystick vertical axis

    if(vexRT[Btn6U] == 1)       //If the group 6 Up button is pressed...
    {
      motor[armMotor] = 40;     //...then raise the arm.
    }
    else if(vexRT[Btn6D] == 1)  //But if the group 6 down button is pressed...
    {
      motor[armMotor] = -40;    //...then lower the arm.
    }
    else                        //But if no button is pressed...
    {
      motor[armMotor] = 0;      //...stop the arm.
    }

	}
}
