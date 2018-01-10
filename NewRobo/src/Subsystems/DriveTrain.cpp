#include "DriveTrain.h"
#include <Joystick.h>
#include <LiveWindow/LiveWindow.h>

#include "Commands/ArcadeDriveWithJoystick.h"

DriveTrain::DriveTrain()
	: Subsystem("drivetrain") {

}

void DriveTrain::InitDefaultCommand (){

}

//This is Arcade Driving
void DriveTrain::Drive(double moveValue, double rotateValue){
	driveTrain.ArcadeDrive(moveValue, rotateValue);
	m_middleH.Set(0);
}

void DriveTrain::ArcadeDrive(frc::Joystick* joy){
	driveTrain.ArcadeDrive(joy->GetY(), joy->GetX());
}

void DriveTrain::HDrive(frc::Joystick* joy){
	driveTrain.TankDrive(joy->GetY(), joy->GetY());
	m_middleH.Set(joy->GetX());
}
