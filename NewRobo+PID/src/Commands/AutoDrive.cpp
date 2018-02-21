#include "Robot.h"
#include "AutoDrive.h"

AutoDrive::AutoDrive(double leftMoveValue, double rightMoveValue){
	Requires(Robot::drivetrain);
	this->rightMoveValue = rightMoveValue;
	this->leftMoveValue = leftMoveValue;
}

// Called just before this Command runs the first time
void AutoDrive::Initialize() {
	Robot::drivetrain->AutoDrive(leftMoveValue, rightMoveValue);
}

// Called repeatedly when this Command is scheduled to run
void AutoDrive::Execute() {


}

// Make this return true when this Command no longer needs to run execute()
bool AutoDrive::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void AutoDrive::End() {
	Robot::drivetrain->Drive(0, 0, 0);
}

void AutoDrive::Interrupted(){
	End();
}

