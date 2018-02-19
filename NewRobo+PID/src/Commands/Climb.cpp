/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include "Robot.h"
#include "Climb.h"
#include "Subsystems/Climber.h"
Climb::Climb(int pulleyDirection, int winchDirection, int timeout):frc::Command("Climb"){
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::climber);
	this->pulleyDirection = pulleyDirection;
	this->winchDirection = winchDirection;
	this->timeout= timeout;
}

// Called just before this Command runs the first time
void Climb::Initialize() {
	if (timeout >0){
		SetTimeout(timeout);

	}
	Robot::climber->togglePole(pulleyDirection);
			Robot::climber->toggleWinch(winchDirection);
}

// Called repeatedly when this Command is scheduled to run
void Climb::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool Climb::IsFinished() {
	if(timeout > 0){
		return IsTimedOut();
	}else{
		return false;
	}
}

// Called once after isFinished returns true
void Climb::End() {
	Robot::climber->togglePole(0);
	Robot::climber->toggleWinch(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Climb::Interrupted() {

}
