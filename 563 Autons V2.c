// 563 Autons
#include "563 Functions V2.c"

#define NUMBER_OF_AUTONS 7

string autonOneName = "1: 19 Pt RL";
void autoOne()
{
	openClawPower(700);
	driveForward(127, 100);
	lift(70);
	wait1Msec(1100);
	haltYo();
	wait1Msec(100);
	driveForward(127, 1100);
	haltYo();
	driveBackward(70, 700);
	haltYo();
	lift(-75);
	wait1Msec(500);
	haltYo();
	pointTurn(75, 300, RIGHT);
	haltYo();
	driveForward(90, 800);
	closeClawPower(500);
	lift(127);
	wait1msec(500);
	haltYo();
	liftStall(10);
	pointTurn(75,300, RIGHT);
	lift(127);
	driveBackward(75, 700);
	openClawPower(500);
	lift(-127);
	openClawPower(700);
	lift(0);
	driveForward(80, 800);
	closeClawPower(800);
	wait1Msec(100);
	lift(127);
	driveBackward(127, 1000);
	openClaw();
	haltYo();

}
string autonTwoName = "8 Pt RR";
void autoTwo()
{
openClawPower(500);
driveForward(127, 300);
pointTurn(75, 380, LEFT);
wait1Msec(500);
driveForward(80, 600);
closeClawPower(200);
lift(100);
wait1Msec(300);
liftStall(15);
wait1Msec(500);
pointTurn(100, 330, LEFT);
wait1Msec(800);
lift(127);
driveBackward(127, 700);
openClawPower(400);
haltYo();
lift(-80);
wait1Msec(1300);
lift(0);
openClawPower(800);
driveForward(80,800);
closeClawPower(700);
wait1Msec(500);
lift(127);
driveBackward(127, 1000);
openClaw();
haltYo();
}
string autonThreeName = "Skills";
void autoThree()
{
//openClawPower(150);
//driveForward(70,700);
//closeClawPower(200);
//driveBackward(90,700);
//pointTurn(80,200,LEFT);
//haltYo();
//openClawPower(500);
//driveForward(127,700);
//closeClawPower(500);
//wait1Msec(250);
//lift(100);
//wait1Msec(500);
//liftStall(20);
//wait1Msec(200);
//pointTurn(127,400,RIGHT);
//wait1Msec(500);
//lift(127);
//driveBackward(127,700);
//openClawPower(500);
//haltYo();
openClawPower(500);
driveForward(127, 300);
pointTurn(75, 380, LEFT);
wait1Msec(500);
driveForward(80, 600);
closeClawPower(200);
lift(100);
wait1Msec(300);
liftStall(15);
wait1Msec(500);
pointTurn(100, 330, LEFT);
wait1Msec(800);
lift(127);
driveBackward(127, 700);
openClawPower(400);
//////////////////////
haltYo();
lift(-80);
wait1Msec(1300);
lift(0);
openClawPower(800);
driveForward(80,800);
closeClawPower(700);
wait1Msec(500);
lift(127);
driveBackward(127, 1000);
openClawPower(200);
////////////////////////////////////
lift(0);
haltYo();
wait1Msec(500);
lift(-80);
driveForward(127,800);
lift(0);
wait1Msec(500);
pointTurn(80,650,LEFT);
wait1Msec(750);
openClawPower(500);
driveForward(80,450);
closeClawPower(500);
driveBackward(80,200);
wait1Msec(750);
lift(100);
wait1Msec(250);
lift(15);
pointTurn(80,500,RIGHT);
wait1Msec(500);
lift(127);
driveBackward(127,550);
openClawPower(350);
///////////////////////////////
lift(0);
wait1Msec(1000);
lift(-70);
driveForward(80,300);
closeClaw();
wait1Msec(750);
lift(0);
pointTurn(100,350,RIGHT);
wait1Msec(500);
driveForward(127,600);
wait1Msec(250);
pointTurn(80,500,LEFT);
wait1Msec(200);
openClawPower(400);
driveForward(127,800);
closeClawPower(500);
wait1Msec(500);
lift(127);
driveBackward(127,950);
openClawPower(300);
////////////
lift(0);
wait1Msec(500);
lift(-90);
driveForward(127,600);
lift(0);
driveForward(127,350);
wait1Msec(1000);
closeClawPower(500);
////////////////////////////////////
lift(127);
driveBackward(127,950);
openClawPower(300);
lift(0);
wait1Msec(500);
lift(-90);
driveForward(127,600);
lift(0);
driveForward(127,350);
wait1Msec(1000);
closeClawPower(500);
///////////////////////////////
lift(127);
driveBackward(127,950);
openClawPower(300);
lift(0);
wait1Msec(500);
lift(-90);
driveForward(127,600);
lift(0);
driveForward(127,350);
wait1Msec(1000);
closeClawPower(500);
///////////////////////////////////////
lift(127);
driveBackward(127,950);
openClawPower(300);
lift(0);
wait1Msec(500);
lift(-90);
driveForward(127,600);
lift(0);
driveForward(127,350);
wait1Msec(1000);
closeClawPower(500);






}
string autonFourName = "4: Block";
void autoFour()
{
	openClawPower(700);
	driveForward(127, 100);
	lift(70);
	wait1Msec(1100);
	haltYo();
	wait1Msec(100);
	driveForward(127, 1100);
	haltYo();
	driveBackward(70, 700);
	haltYo();
	lift(-75);
	closeClawPower(200);
	wait1Msec(500);
	haltYo();
}
string autonFiveName = "5: None";
void autoFive()
{

}

string autonSixName = "6: None";
void autoSix()
{

}
string autonSevenName = "7: None";
void autoSeven()
{

}
