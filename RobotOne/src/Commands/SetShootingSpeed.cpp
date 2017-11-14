#include "SetShootingSpeed.h"
#include "Robot.h"

SetShootingSpeed::SetShootingSpeed(double speed):
frc::Command("SetShootingSpeed") {
	this->speed = speed;
	Requires(Robot::shootingmotor.get());
}

// Called just before this Command runs the first time
void SetShootingSpeed::Initialize() {
	//Changing the speed of the shooting motor by setting it to the speed of the parameter
	Robot::shootingmotor->setSpeed(speed);
}


// Make this return true when this Command no longer needs to run execute()
bool SetShootingSpeed::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void SetShootingSpeed::End() {

}

