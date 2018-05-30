/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include <Commands/SpinPulley.h>
#include <Subsystems/Pulley.h>
#include "Robot.h"
SpinPulley::SpinPulley(int pulleyDirection, int timeout):frc::Command("SpinPulley"){
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::pulley);
	this->pulleyDirection = pulleyDirection;
	this->timeout= timeout;
}

// Called just before this Command runs the first time
void SpinPulley::Initialize() {
	if (timeout > 0){
		SetTimeout(timeout);

	}
	Robot::pulley->togglePole(pulleyDirection);
}

// Called repeatedly when this Command is scheduled to run
void SpinPulley::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool SpinPulley::IsFinished() {
	if(timeout > 0){
		return IsTimedOut();
	}else{
		return true;
	}
}

// Called once after isFinished returns true
void SpinPulley::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SpinPulley::Interrupted() {

}
