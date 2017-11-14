#include "DriveTrain.h"
#include <Joystick.h>
#include <LiveWindow/LiveWindow.h>

#include "Commands/ArcadeDriveWithJoystick.h"

DriveTrain::DriveTrain()
	: Subsystem("DriveTrain") {

}

void DriveTrain::InitDefaultCommand (){
	SetDefaultCommand(new ArcadeDriveWithJoystick());
}


void DriveTrain::Drive(double left, double right){
	driveTrain.TankDrive(left, right);
}

void DriveTrain::Drive(frc::Joystick* joy){
	driveTrain.ArcadeDrive(joy);
}
