#include "DriveTrain.h"
#include <Joystick.h>
#include <LiveWindow/LiveWindow.h>

#include "Commands/ArcadeDriveWithJoystick.h"

DriveTrain::DriveTrain()
	: Subsystem("drivetrain") {

		//Inverting all of the motor because the motor are wired in reverse
		driveTrain.SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
		driveTrain.SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
		driveTrain.SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
		driveTrain.SetInvertedMotor(RobotDrive::kRearRightMotor, true);
}

void DriveTrain::InitDefaultCommand (){

}


void DriveTrain::Drive(double moveValue, double rotateValue){
	driveTrain.Drive(moveValue, rotateValue);
}

void DriveTrain::Drive(frc::Joystick* joy){
	driveTrain.ArcadeDrive(joy);
}
