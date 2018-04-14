/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "DriveTrain.h"
#include "../RobotMap.h"
#include "Robot.h"
#include "Commands/Drive.h"
DriveTrain::DriveTrain()
    : frc::Subsystem("driveTrain") {
	stick = Robot::oi->GetController();
}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new Drive());
}
void DriveTrain::ArcadeDrive(){
	driveTrain.ArcadeDrive( stick->GetY(), stick->GetX());
}
void DriveTrain::Spin180(){
	LMotor.Set(1);
	RMotor.Set(1);
}
void DriveTrain::StopMotors(){
	LMotor.Set(0);
	RMotor.Set(0);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
