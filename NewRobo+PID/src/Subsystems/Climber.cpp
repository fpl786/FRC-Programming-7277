/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Climber.h"
#include <Spark.h>
Climber::Climber() : Subsystem("ExampleSubsystem") {
	winch = new frc::Spark(3);
	pulley = new frc::Spark(2);
}

void Climber::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Climber::togglePole(int direction){
	pulley->Set(direction);
}
void Climber::toggleWinch(int direction){
	winch->Set(direction);
}

