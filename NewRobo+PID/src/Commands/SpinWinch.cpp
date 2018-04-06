/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include <Commands/SpinWinch.h>
#include <Subsystems/Winch.h>
#include "Robot.h"
SpinWinch::SpinWinch( int winchDirection, int timeout):frc::Command("SpinWinch"){
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::winch);
	this->winchDirection = winchDirection;
	this->timeout= timeout;
}

// Called just before this Command runs the first time
void SpinWinch::Initialize() {
	if (timeout > 0){
		SetTimeout(timeout);

	}
	Robot::winch->toggleWinch(winchDirection);
}

// Called repeatedly when this Command is scheduled to run
void SpinWinch::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool SpinWinch::IsFinished() {
	if(timeout > 0){
		return IsTimedOut();
	}else{
		return true;
	}
}

// Called once after isFinished returns true
void SpinWinch::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SpinWinch::Interrupted() {

}
