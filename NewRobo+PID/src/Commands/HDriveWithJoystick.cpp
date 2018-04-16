#include "HDriveWithJoystick.h"
#include "Robot.h"

HDriveWithJoystick::HDriveWithJoystick() :
			frc::Command("HDriveWithJoystick") {
				Requires(Robot::drivetrain);
}

void HDriveWithJoystick::Execute() {
	Robot::drivetrain->MainDrive(Robot::oi->GetJoystick(),Robot::oi->GetController());
}

// Make this return true when this Command no longer needs to run execute()
bool HDriveWithJoystick::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void HDriveWithJoystick::End() {
	Robot::drivetrain->Drive(0, 0, 0);
}

void HDriveWithJoystick::Interrupted(){
	End();
}



