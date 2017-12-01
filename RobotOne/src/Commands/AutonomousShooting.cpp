#include "AutonomousShooting.h"
#include "Robot.h"

AutonomousShooting::AutonomousShooting(double speed, double timeout):
frc::Command("SetShootingSpeed") {
	Requires(Robot::shootingmotor);
	this->speed = speed;
	this->timeout = timeout;
}


// Called just before this Command runs the first time
void AutonomousShooting::Initialize() {
	//Changing the speed of the shooting motor by setting it to the speed of the parameter
	Robot::shootingmotor->setSpeed(speed);
	SetTimeout(timeout);
}


// Make this return true when this Command no longer needs to run execute()
bool AutonomousShooting::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void AutonomousShooting::End() {
	Robot::shootingmotor->setSpeed(0);
}

void AutonomousShooting::Interrupted(){
	End();
}

