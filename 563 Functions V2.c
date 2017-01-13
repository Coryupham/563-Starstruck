#define RIGHT	0
#define LEFT	1
const	int tsArray[128] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	20, 21, 21, 21, 22, 22, 22, 23, 24, 24,
	25, 25, 25, 25, 26, 27, 27, 28, 28, 28,
	28, 29, 30, 30, 30, 31, 31, 32, 32, 32,
	33, 33, 34, 34, 35, 35, 35, 36, 36, 37,
	37, 37, 37, 38, 38, 39, 39, 39, 40, 40,
	41, 41, 42, 42, 43, 44, 44, 45, 45, 46,
	46, 47, 47, 48, 48, 49, 50, 50, 51, 52,
	52, 53, 54, 55, 56, 57, 57, 58, 59, 60,
	61, 62, 63, 64, 65, 66, 67, 67, 68, 70,
	71, 72, 72, 73, 74, 76, 77, 78, 79, 79,
	80, 81, 83, 84, 84, 86, 86, 87, 87, 88,
	88, 89, 89, 90, 90,127,127,127
};

int trueSpeed(int power){
	return ((power>0)?1:-1)*tsArray[power*((power>0)?1:-1)];
}
void
drive()
{
	motor[port9] = trueSpeed(vexRT[Ch2]);
	motor[port6] = trueSpeed(vexRT[Ch3]);
	motor[port3] = trueSpeed(vexRT[Ch2]);
	motor[port2] = trueSpeed(vexRT[Ch3]);
}

int iDes;
task clawControll()
{
	if ( vexRT[ Btn5U] || vexRT[Btn5D])
	{
		motor [clawR] = (vexRT[Btn5U] - vexRT [Btn5D]) * 127;
		motor [clawL] = -(vexRT[Btn5U] - vexRT [Btn5D]) * 127;

		iDes = SensorValue [in3];
	}
	else
	{
		motor[clawR] = (iDes - SensorValue[in3] ) * 0.06;
		motor[clawL] = -(iDes - SensorValue[in3] ) * 0.06;
	}

}
task claw()
{
	while (true)
	{

		if(vexRT[Btn5U] == 1)
		{
			motor[clawR] = 110;
			motor[clawL] = 110;
		}
		else if(vexRT[Btn5D] == 1)
		{
			motor[clawR] = -127;
			motor[clawL] = -127;
		}
		else{
			motor[clawR] = -10;
			motor[clawL] = -10;
		}
		wait1Msec (20);
	}
}

void
haltYo()
{
	motor[port1] = 0;
	motor[port2] = 0;
	motor[port3] = 0;
	motor[port4] = 0;
	motor[port5] = 0;
	motor[port6] = 0;
	motor[port7] = 0;
	motor[port8] = 0;
	motor[port9] = 0;
	motor[port10] = 0;
}

void
lift(int power)
{
	motor[port5] = power;
	motor[port7] = power;
	motor[port4] = power;
	motor[port8] = power;
}

void
liftStall(int power)
{
	motor[port5] = power;
	motor[port7] = power;
	motor[port4] = power;
	motor[port8] = power;
}

void
driveForward (int power, int distance)
{
	resetMotorEncoder(backRightDrive);
	resetMotorEncoder(backLeftDrive);
	for(int i = 0; i < power; i++)
	{
		motor[backRightDrive] = i;
		motor[frontLeftDrive] = i;
		motor[backLeftDrive] = i;
		motor[frontRightDrive] = i;
		wait1Msec(5);
	}

	while(abs(getMotorEncoder(backLeftDrive)) < abs(distance) && abs(getMotorEncoder(backRightDrive)) < abs(distance))
	{
		motor[backRightDrive] = power;
		motor[frontLeftDrive] = power;
		motor[backRightDrive] = power;
		motor[frontRightDrive] = power;
	}
	motor[backRightDrive] = 0;
	motor[backLeftDrive] = 0;
	motor[frontLeftDrive] = 0;
	motor[frontRightDrive] = 0;
}

void
driveBackward(int power, int distance)
{
	resetMotorEncoder(backRightDrive);
	resetMotorEncoder(backLeftDrive);
	while(abs(getMotorEncoder(backLeftDrive)) < abs(distance) && abs(getMotorEncoder(backRightDrive)) < abs(distance))
	{
		motor[backLeftDrive] = -power;
		motor[backRightDrive] = -power;
		motor[frontLeftDrive] = -power;
		motor[frontRightDrive] = -power;
	}
	motor[backLeftDrive] = 0;
	motor[frontRightDrive] = 0;
	motor[backRightDrive] = 0;
	motor[frontLeftDrive] = 0;
}

void
pointTurn(int power, int distance, int leftOrRight)
{
	resetMotorEncoder(backRightDrive);
	resetMotorEncoder(backLeftDrive);
	if (leftOrRight == 1)//left turn
	{
		while(abs(getMotorEncoder(backLeftDrive)) < abs(distance) && abs(getMotorEncoder(backRightDrive)) < abs(distance))
		{
			motor[backLeftDrive] = -power;
			motor[frontLeftDrive] = -power;
			motor[backRightDrive] = power;
			motor[frontRightDrive] = power;
		}
	}
	if (leftOrRight == 0)///right turn
	{
			while(abs(getMotorEncoder(backLeftDrive)) < abs(distance) && abs(getMotorEncoder(backRightDrive)) < abs(distance))
		{
			motor[backLeftDrive] = power;
			motor[frontLeftDrive] = power;
			motor[backRightDrive] = -power;
			motor[frontRightDrive] = -power;
		}
	}
	motor[backLeftDrive] = 0;
	motor[frontLeftDrive] = 0;
	motor[backRightDrive] = 0;
	motor[frontRightDrive] = 0;
}

void
closeClaw()
{
	while (SensorValue[in3] < 2600)
	{
	motor [clawR] = 127;
	motor [clawL] = 127;
	}
	motor [clawR] = 10;
	motor [clawL] = 10;
}

void
openClaw()
{
	while (SensorValue[in3] > 940)
	{
		motor [clawR] = -127;
		motor [clawL] = -127;
	}
		motor [clawR] = -15;
		motor [clawL] = -15;

}
