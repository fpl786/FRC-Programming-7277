#include "ResetSensor.h"
#include "Robot.h"

ResetSensor::ResetSensor() {
	Requires(Robot::drivetrain);
}

// Called just before this Command runs the first time
void ResetSensor::Initialize() {
	Robot::drivetrain->ResetSensor();
}


// Make this return true when this Command no longer needs to run execute()
bool ResetSensor::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ResetSensor::End() {

}

